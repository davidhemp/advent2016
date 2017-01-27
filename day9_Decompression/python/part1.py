import re

def decompress(string):
    rgx = "(\w+)?\((\d+)x(\d+)\)"
    rtn = ""
    while len(string) > 0:
        m = re.match(rgx, string)
        if m:
            if m.group(1) == None:
                start = ""
            else:
                start = m.group(1)
            l = len(m.group(0))
            rep_l = int(m.group(2))
            reps = int(m.group(3))
            end = string[l + rep_l:]
            add = string[l:l+rep_l]*reps
            rtn += start + add
            string = end
        else:
            rtn += string
            string = ""
    return rtn



def run(filename="input.txt"):
    f = open(filename)
    data = f.read().strip()
    return len(decompress(data))

if __name__ == "__main__":
    print(run())
