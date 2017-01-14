def move(data):
    bounds = [-1, 3]
    code = ""
    x = y = 1
    for l in data:
        for c in l:
            if (c == 'U'):
                y -= 1
                if (y < 0):
                    y = 0
            if (c == 'D'):
                y += 1
                if (y > 2):
                    y = 2
            if (c == 'L'):
                x -= 1
                if (x < 0):
                    x = 0
            if (c == 'R'):
                x += 1
                if (x > 2):
                    x = 2
        code += "%i" %((x+1) +(y*3))
    return code

def run(path = ""):
    with open(path + "input.txt") as f:
        data = [line for line in f]
        code = move(data)
    return code

if __name__ == "__main__":
    print(run())
