def run():
    n = 0
    with open("input.txt") as f:

        for line in f.readlines():
            items = sorted([int(line[:5]), int(line[5:10]), int(line[10:])])
            if (items[0] + items[1] > items[2]):
                n += 1
    print(n)
#983
