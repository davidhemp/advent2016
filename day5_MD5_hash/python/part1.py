import hashlib

def hash(s):
    return hashlib.md5(s).hexdigest()[:9]

def run(input_string="uqwqemis"):
    rtn = ""
    n = 0
    keys = []
    while len(rtn) < 8:
        test_hash = hash(input_string + str(n))
        if test_hash[:5] == "00000":
            keys.append(n)
            rtn += test_hash[5]
        n += 1
    return rtn, keys

if __name__ == "__main__":
    print(run())
