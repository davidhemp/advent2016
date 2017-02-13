def find_allowed(blist):
    minimum = blist[0][0]
    maximum = blist[0][1]
    excluded = 0
    for ip_range in blist[1:]:
        if ip_range[0] <= maximum+1 and ip_range[1] > maximum:
            maximum = ip_range[1]
        elif ip_range[0] > maximum:
            excluded += maximum - minimum + 2
            minimum = ip_range[0]
            maximum = ip_range[1]
    return 2**32-excluded

def run(path = ""):
    blist = []
    with open(path +"input.txt") as f:
        for line in f:
            blist.append([int(i) for i in line.strip().split('-')])
    blist = sorted(blist)
    return find_allowed(blist)

if __name__ == "__main__":
    print(run())
