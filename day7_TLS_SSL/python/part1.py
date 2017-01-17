import re

def search_string(teststring):
    for i in range(len(teststring)-3):
        a = teststring[i]
        b = teststring[i+1]
        mask = a + b + b + a
        if mask in teststring and a != b:
            return True
    return False

def search_line(line):
    out_brackets = []
    in_brackets = []
    pos = 0
    for m in re.split("[\[\]]", line.strip()):
        if pos%2 != 0:
            out_brackets.append(search_string(m))
        else:
            in_brackets.append(search_string(m))
        pos += 1
    if True in in_brackets and True not in out_brackets:
        return 1
    else:
        return 0

def run(path =""):
    n = 0
    with open(path + 'input.txt') as f:
        for line in f:
            n += search_line(line)
    return n

if __name__ == "__main__":
    print(run())
