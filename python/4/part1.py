from operator import itemgetter
import re
import string

def run():
    n = 0
    sector_sum = 0
    regex = r'([a-z-]+)(\d+)\[(\w+)\]'
    with open("input.txt") as f:
        for name, sector_id, checksum in re.findall(regex, f.read()):
            letters = sorted(set(name.replace('-', '')))
            count_letters = []
            for l in letters:
                count_letters.append([l, name.count(l)])
            count_letters.sort(key=itemgetter(1), reverse=True)
            # built_checksum = "".join(c for c,n in count_letters)
            #Pre-defined is faster than post selected
            built_checksum = count_letters[0][0] + \
                             count_letters[1][0] + \
                             count_letters[2][0] + \
                             count_letters[3][0] + \
                             count_letters[4][0]
            if built_checksum == checksum:
                n += 1
                sector_sum += int(sector_id)
    print(n, sector_sum)
