import re

def search(teststring):
    for i in range(len(teststring)-3):
        a = teststring[i]
        b = teststring[i+1]
        mask = a + b + b + a
        if mask in teststring and a != b:
            return True
    return False

def run():
    n = 0
    with open('input.txt') as f:
        for line in f:
            brackets = []
            passed = []
            pos = 0
            for m in re.findall(rgx, line):
                if pos%2 != 0:
                    brackets.append(search(m[0]))
                else:
                    passed.append(search(m[0]))

                pos += 1
            if True in passed and True not in brackets:
                n += 1
    # print(n)
# run()
