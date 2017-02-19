def operation(password, line):
    items = [i for i in line.strip().split(' ')]
    if items[0] == "swap":
        try:
            j = int(items[2])
            i = int(items[5])
        except ValueError:
            j = password.index(items[2])
            i = password.index(items[5])
        old = password[i]
        password[i] = password[j]
        password[j] = old
    elif items[0] == "reverse":
        i = int(items[2])
        j = int(items[4])
        for c,k in zip(reversed(password[i:j+1]), range(i,j+1)):
            password[k] = c
    elif items[0] == "rotate":
        try:
            i = int(items[2])
        except ValueError:
            i = password.index(items[6])
            search_chr = items[6]
            j = -2
            while (password.index(search_chr) + j)%len(password) != i:
                password.append(password.pop(0))
                j = password.index(search_chr)
                if j >= 4:
                    j += 1
                j += 1
                j = j%len(password)
        else:
            new_password = [""]*len(password)
            if items[1] == "left":
                j = 1
            else:
                j = -1
            for c,k in zip(password, range(10)):
                pos = (k + i*j)%len(password)
                new_password[pos] = c
            password = new_password
    elif items[0] == "move":
        j = int(items[2])
        i = int(items[5])
        c = password.pop(i)
        password.insert(j, c)
    else:
        raise ValueError("Operation not found", line)
    return password

def run(path = ""):
    data = open(path + "input.txt").readlines()
    password = [i for i in "fbgdceah"]
    for line in data[::-1]:
        password = operation(password, line)
    return "".join(password)

if __name__ == "__main__":
    print(run())
