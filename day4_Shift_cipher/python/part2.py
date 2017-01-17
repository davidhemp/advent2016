from operator import itemgetter
import re
import string

def search_line(line, count):
    regex = r'([a-z-]+)(\d+)\[(\w+)\]'
    for encoded, sector_id, checksum in re.findall(regex, line):
        letters = sorted(set(encoded.replace('-', '')))
        count_letters = [[l, encoded.count(l)] for l in letters]
        count_letters.sort(key=itemgetter(1), reverse=True)
        built_checksum = ""
        for c in count_letters[:5]:
            built_checksum += c[0]
        decoded = ""
        if built_checksum == checksum:
            decoded = decode(encoded, sector_id)
            count += 1
        return count, decoded, sector_id

def decode(encoded, sector_id):
    decoded = ""
    ord_a = ord('a')
    for l in encoded:
        i = (int(sector_id) + ord(l) - ord_a)%26
        decoded += string.lowercase[i]
    return decoded

def run(path=""):
    n = 0
    with open(path + "input.txt") as f:
        for line in f:
            n, decoded, sector_id = search_line(line, n)
            if "north" in decoded:
                break
    return decoded, sector_id

if __name__ == "__main__":
    print(run())
