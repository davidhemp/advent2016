import re

def compare(line):
    a, b, c = sorted([int(i) for i in re.findall(r"(\d+)", line)])
    if (a + b > c):
        return 1
    else:
        return 0

def run(path=""):
    n = 0
    with open(path + "input.txt") as f:
        for line in f.readlines():
                n += compare(line)
    return n

#983
if __name__ == "__main__":
    print(run())
