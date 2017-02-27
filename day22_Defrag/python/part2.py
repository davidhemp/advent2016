from operator import itemgetter

def run(filename = "input.txt"):
    lines = open(filename).readlines()[2:]
    used = []
    avail = []
    #x36-y24
    #x34-y28
    rows = 25
    cols = 37
    data = [["%02i" %i] for i in range(rows+1)]
    print("  " + "".join(["%02i" %i for i in range(cols+1)]))
    for j in range(cols):
        for i in range(rows):
            node = lines[i+j*rows]
            line = filter(None, node.strip().split(" "))
            percert = int(line[4][:-1])
            used = int(line[2][:-1])
            if used > 100:
                data[i].append('#')
            elif percert != 0:
                data[i].append('.')
            else:
                data[i].append('_')
    data[0][1] = '+'
    data[0][-1] = '*'
    for line in data:
        print(" ".join(line))
        
if __name__ == "__main__":
    print(run())
