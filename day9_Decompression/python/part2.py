import re

def decompress(string):
    rgx = "(\w+)?\((\d+)x(\d+)\)"
    rtn = 0
    while len(string) > 0:
        to_product = []
        final = 0
        m = re.match(rgx, string)
        if m:
            if m.group(1) != None:
                rtn += len(m.group(1))
            final = int(m.group(2))
            test_string = string[:len(m.group(0)) + final]
            string = string[len(m.group(0)) + final:]
            while m:
                final = int(m.group(2))
                to_product.append(int(m.group(3)))
                print(rtn, m.groups(), test_string)
                test_string = test_string[len(m.group(0)):]
                m = re.match(rgx, test_string)
            print(rtn, final, to_product)
            for i in to_product:
                final *= i
            rtn += final
        else:
            rtn += len(string)
            string = ""
    return rtn


def run(filename="input.txt"):
    f = open(filename)
    data = f.read().strip()
    return len(decompress(data))

if __name__ == "__main__":
    print(run())
