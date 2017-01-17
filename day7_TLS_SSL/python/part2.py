import re

def search_line(line):
    matchs = re.split("[\[\]]", line.strip())
    subnets =  matchs[1::2]
    supernets = matchs[::2]
    passed = 0
    for supernet in supernets:
        for i in range(len(supernet)-2):
            a, b, c = supernet[i:i+3]
            if a == c and a != b and b != c:
                mask = b+a+b
                for subnet in subnets:
                    if mask in subnet:
                        passed = 1
                        break
    return passed

def run(path=""):
    n = 0
    with open(path + 'input.txt') as f:
        for line in f:
                n += search_line(line)
    return n
if __name__ == "__main__":
    print(run())
