from operator import itemgetter

def run(filename = "testinput.txt"):
    lines = open(filename).readlines()
    used = []
    avail = []
    for line in lines[2:]:
        data = filter(None, line.strip().split(' '))
        used.append([int(data[2][:-1]), int(data[3][:-1])])
        avail.append(int(data[3][:-1]))
    used = sorted(used, reverse=True)
    avail = sorted(avail)
    pairs = 0
    n = 0
    fw = open('log.txt', 'w')
    for i in used:
        if i[0] > 0:
            if i[0] <= i[1]:
                pairs -= 1
            j = 0
            try:
                while i[0] > avail[j] and j <= len(avail)-1:
                    j += 1
            except IndexError:
                j += 1
            pairs += len(avail[j:])
    fw.close()
    return pairs

if __name__ == "__main__":
    print(run())
