import hashlib

def hash(s):
    return hashlib.md5(s).hexdigest()[:9]

def run(input_string="uqwqemis"):
    rtn = ["-" for i in range(8)]
    n = 0
    keys = []
    while len(keys) < 8:
        test_hash = hash(input_string + str(n))
        if test_hash[:5] == "00000":
            try:
                msg = ""
                if rtn[int(test_hash[5])] is "-":
                    rtn[int(test_hash[5])] = test_hash[6]
                    keys.append(n)
                else:
                    msg = "skipped - Already have that char"
            except ValueError:
                msg = "skipped - That's a letter"
                pass
            except IndexError:
                msg = "skipped - Postion out of bounds"
                pass
            print("".join(rtn), n, test_hash[6], test_hash[5], msg)
        n += 1
    return "".join(rtn), keys

if __name__ == "__main__":
    print(run())
