def run():
    n = 0
    j = 0
    with open("input.txt") as f:
        values = [[],[],[]]
        for line in f.readlines():
            for i in range(3):
                values[i].append(int(line[i*5:(i+1)*5]))
            j += 1
            if j == 3:
                for i in range(3):
                    items = sorted(values[i])
                    if (items[0] + items[1] > items[2]):
                        n += 1
                values = [[],[],[]]
                j = 0
    # print(n)
#983
