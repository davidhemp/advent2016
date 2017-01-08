import re

with open('testinput.txt') as f:
    for line in f.readlines():
        m = re.search(line.strip(), "rect (\d+)x(\d+)")
        print(len(m.group))
        if m > 0:
            print("beep")
        else:
            m = re.match(line.strip(), "rotate (column|row) (x|y)=(\d+) by (\\d+)")
            print('boop')
