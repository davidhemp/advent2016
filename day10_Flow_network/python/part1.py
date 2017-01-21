import re

class bot(object):
    def __init__(self, number):
        self.number = number
        self.chips = []
        self.high = None
        self.low = None

def chips_at_outputs(outputs):
    total = 0
    for key in outputs:
        total += len(outputs[key].chips)
    return total

def load_chips(filename, bots, outputs):
    chip_count = 0
    straightRGX = r"value (\d+) goes to bot (\d+)"
    conditionalRGX = r"bot (\d+) gives low to (output|bot) (\d+) and high to (output|bot) (\d+)"
    with open(filename) as f:
        active_bots = []
        for line in f:
            m = re.search(straightRGX, line)
            if m != None:
                bots[int(m.group(2))].chips.append(int(m.group(1)))
                chip_count += 1
            m = re.search(conditionalRGX, line)
            #using eval could be considered bad practice but
            if m != None:
                bots[int(m.group(1))].low = \
                    eval(m.group(2) + "s")[int(m.group(3))]
                bots[int(m.group(1))].high = \
                    eval(m.group(4) + "s")[int(m.group(5))]
    return bots, chip_count

def enable_flow(bots, outputs, chip_count):
    run = True
    from_61_to_17 = 0
    while chips_at_outputs(outputs) < chip_count:
        run = False
        del_keys = []
        for key in bots:
            if 61 in bots[key].chips and 17 in bots[key].chips:
                from_61_to_17 = bots[key].number
            if len(bots[key].chips) == 2:
                dest_high = bots[key].high
                dest_low = bots[key].low
                if bots[key].chips[0] - bots[key].chips[1] < 0 :
                    dest_high.chips.append(bots[key].chips[1])
                    dest_low.chips.append(bots[key].chips[0])
                else:
                    dest_low.chips.append(bots[key].chips[1])
                    dest_high.chips.append(bots[key].chips[0])
                del_keys.append(key)
        for key in del_keys:
            del bots[key]
    return outputs, from_61_to_17

def run(filename="input.txt"):
    bots = dict()
    outputs = dict()
    for i in range(220):
        bots[i] = bot(i)
    for i in range(22):
        outputs[i] = bot(i)
    bots, chip_count = load_chips(filename, bots, outputs)
    return enable_flow(bots, outputs, chip_count)

if __name__ == "__main__":
    outputs, from_61_to_17 = run()
    print(outputs[0].chips[0]*outputs[1].chips[0]*outputs[2].chips[0])
    print(from_61_to_17)
