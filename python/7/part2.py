import re

def run():
    n = 0
    with open('input.txt') as f:
        for line in f:
            matchs = re.split("[\[\]]", line.strip())
            subnets =  matchs[1::2]
            supernets = matchs[::2]
            passed = False
            for supernet in supernets:
                for i in range(len(supernet)-2):
                    a, b, c = supernet[i:i+3]
                    if a == c and a != b and b != c:
                        mask = b+a+b
                        for subnet in subnets:
                            if mask in subnet:
                                passed = True
                                break
            if passed:
                n += 1
    print(n)
run()
