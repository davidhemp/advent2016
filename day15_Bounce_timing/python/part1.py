import re

class Disc(object):
    def __init__(self, args):
        self.start = int(args[1])
        self.no_positions = int(args[0])

    def position(self, time):
        return (time+self.start)%self.no_positions

def run(filename="input.txt"):
    rgx = r'\s(\d+)'
    discs = []
    with open(filename) as f:
        for line in f:
            m = re.findall(rgx, line)
            discs.append(Disc(m))

    #part2 adds another disc
    # discs.append(Disc([11, 0]))
    height = len(discs)
    time = 0
    while height > 0:
        time += 1
        for disc in discs:
            if disc.position(time) != 0:
                height = len(discs)
                break
            else:
                height -= 1
                time += 1
    return (time - len(discs) - 1)

if __name__ == "__main__":
    print(run())
