from operator import itemgetter

def find_min(blist):
    minimum = blist[0][0]
    maximum = blist[0][1]
    for ip_range in blist[1:]:
        if ip_range[0] <= maximum+1 and ip_range[1] > maximum:
            maximum = ip_range[1]
        elif ip_range[0] > maximum:
            break
    return maximum+1

def run(path = ""):
    blist = []
    with open(path +"input.txt") as f:
        for line in f:
            blist.append([int(i) for i in line.strip().split('-')])
    blist = sorted(blist)
    return find_min(blist)

if __name__ == "__main__":
    print(run())
