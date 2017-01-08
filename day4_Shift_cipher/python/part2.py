from operator import itemgetter
import re
import string

def run():
    n = 0
    sector_sum = 0
    regex = r'([a-z-]+)(\d+)\[(\w+)\]'
    ord_a = ord('a')
    with open("input.txt") as f:
        for encoded, sector_id, checksum in re.findall(regex, f.read()):
            encoded = encoded.replace('-', '')
            letters = sorted(set(encoded.replace('-', '')))
            count_letters = []
            for l in letters:
                count_letters.append([l, encoded.count(l)])
            count_letters.sort(key=itemgetter(1), reverse=True)
            built_checksum = count_letters[0][0] + \
                             count_letters[1][0] + \
                             count_letters[2][0] + \
                             count_letters[3][0] + \
                             count_letters[4][0]
            if built_checksum == checksum:
                name = ""
                for l in encoded:
                    i = (int(sector_id) + ord(l) - ord_a)%26
                    name += string.lowercase[i]
                if "north" in name:
                    print(sector_id)
run()
