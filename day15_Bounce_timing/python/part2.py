import re

class Disc(object):
    def __init__(self, args):
        self.start = int(args[2])
        self.no_positions = int(args[1])

    def position(self, time):
        return (time+self.start)%self.no_positions

def run():
    rgx = r'Disc #(\d+) has (\d+) positions; at time=0, it is at position (\d+)'
    discs = []
    with open('input.txt') as f:
        for line in f:
            m = re.match(rgx, line)
            discs.append(Disc(m.groups()))

    #part2 adds another disc
    discs.append(Disc([7, 11, 0]))
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
    print(time - len(discs) - 1)
