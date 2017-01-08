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

filename = "input.txt"
bots = dict()
outputs = dict()
for i in range(220):
    bots[i] = bot(i)
for i in range(22):
    outputs[i] = bot(i)
inputted_chips = 0
with open(filename) as f:
    straightRGX = r"value (\d+) goes to bot (\d+)"
    conditionalRGX = r"bot (\d+) gives low to (output|bot) (\d+) and high to (output|bot) (\d+)"
    for line in f:
        m = re.search(straightRGX, line)
        if m != None:
            bots[int(m.group(2))].chips.append(int(m.group(1)))
            inputted_chips += 1
        m = re.search(conditionalRGX, line)
        if m != None:
            bots[int(m.group(1))].low = eval(m.group(2) + "s")[int(m.group(3))]
            bots[int(m.group(1))].high = eval(m.group(4) + "s")[int(m.group(5))]

while (chips_at_outputs(outputs) < inputted_chips):
    for key in bots:
        if len(bots[key].chips) == 2:
            if 61 in bots[key].chips and 17 in bots[key].chips:
                print(bots[key].chips, bots[key].number)
            bots[key].low.chips.append(min(bots[key].chips))
            bots[key].high.chips.append(max(bots[key].chips))
            bots[key].chips = []
        elif len(bots[key].chips) > 2:
            raise ValueError('Too many chips at bot %s' %bots[key].number)
for key in outputs:
    print(outputs[key].number, outputs[key].chips)
