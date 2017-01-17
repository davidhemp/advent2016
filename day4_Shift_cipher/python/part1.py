from operator import itemgetter
import re

def search_line(line, count, sector_sum):
    regex = r'([a-z-]+)(\d+)\[(\w+)\]'
    for name, sector_id, checksum in re.findall(regex, line):
        letters = sorted(set(name.replace('-', '')))
        count_letters = [[l, name.count(l)] for l in letters]
        count_letters.sort(key=itemgetter(1), reverse=True)
        built_checksum = ""
        # '+' is faster than join
        for c in count_letters[:5]:
            built_checksum += c[0]
        # built_checksum = "".join(c[0] for c in count_letters[:5])
        if built_checksum == checksum:
            count += 1
            sector_sum += int(sector_id)
        return count, sector_sum

def run(path=""):
    n = 0
    sector_sum = 0
    with open(path + "input.txt") as f:
        for line in f:
            n, sector_sum = search_line(line, n, sector_sum)
    return n, sector_sum

if __name__ == "__main__":
    print(run())
