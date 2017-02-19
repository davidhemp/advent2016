def find_allowed(blist, max_value=2**32-1):
    minimum = blist[0][0]
    maximum = blist[0][1]
    included = 0
    for ip_range in blist[1:]:
        if ip_range[0] <= maximum+1 and ip_range[1] > maximum:
            maximum = ip_range[1]
        elif ip_range[0] > maximum:
            minimum = ip_range[0]
            included += minimum - maximum - 1
            maximum = ip_range[1]
    return included + (max_value - maximum)

def run(path = "", filename = "input.txt", max_value=2**32-1):
    blist = []
    with open(path + filename) as f:
        for line in f:
            blist.append([int(i) for i in line.strip().split('-')])
    blist = sorted(blist)
    return find_allowed(blist, max_value)

if __name__ == "__main__":
    print(run())
