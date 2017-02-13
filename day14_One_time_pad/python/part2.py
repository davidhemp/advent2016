import hashlib
import re
from operator import itemgetter

def hash(s):
    n = 2016
    while n > 0:
        s = hashlib.md5(s).hexdigest()
        n -= 1
    return s

def rgx_search(string):
    rgx = r"([a-f0-9])\1{2,}"
    m = re.search(rgx, string)
    try:
        if len(m.group(0)) == 5:
            return 5, m.group(1), string
        else:
            return 3, m.group(1), string
    except AttributeError:
        return False

def run(input_string="ihaygndm"):
    keys = []
    potentional_keys = dict()
    for c in "0123456789abcdef":
        potentional_keys[c] = []
    n = 0
    while len(keys) < 64:
        found = rgx_search((hash(input_string + str(n))))
        if found:#yes this is horrid, I know...
            if found[0] >= 5:
                for key in potentional_keys[found[1]]:
                    if key[1] > n - 1000:
                        keys.append(key)
                potentional_keys[found[1]] = []
            else:
                potentional_keys[found[1]].append([found[2], n])
        n += 1
    keys = sorted(keys, key=itemgetter(1))
    # for key in keys:
    #     print(key)
    return keys[63][1]

if __name__ == "__main__":
    print(run())
