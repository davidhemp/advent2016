import re

def count(data):
    n = 0
    values = [int(i) for i in re.findall(r"(\d+)", data)]
    for i in xrange(0, len(values), 9):
        for j in xrange(0, 3):
            a, b, c = sorted(values[i+j:i+j+9:3])
            if (a + b > c):
                n += 1
    return n

def load(path=""):
    with open(path + "input.txt") as f:
        data = f.read()
    return data

def run(path=""):
    data = load(path)
    return count(data)
#983
if __name__ == "__main__":
    print(run())
