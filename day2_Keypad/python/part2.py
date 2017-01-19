forbidden_list = [ [3,0],
                   [2,1], [4,1],
                   [1,2], [5,2],
                   [0,3], [6,3],
                   [1,4], [5,4],
                   [2,5], [4,5],
                   [3,6] ]

def move(line, x, y):
    for l in line:
        for c in l:
            if (c == 'U') and [x,y-1] not in forbidden_list:
                y -= 1
            if (c == 'D') and [x,y+1] not in forbidden_list:
                y += 1
            if (c == 'L') and [x-1,y] not in forbidden_list:
                x -= 1
            if (c == 'R') and [x+1,y] not in forbidden_list:
                x += 1
    return [x,y]

def decode(x, y):
    l = [['1'],
         ['2', '3', '4'],
         ['5', '6', '7', '8', '9'],
         ['A', 'B', 'C'],
         ['D']]
    return l[y - 1][x - y%3 - 1]

def run(path = ""):
    x = 1
    y = 3
    rtn = ""
    with open(path + "input.txt") as f:
        for line in f:
            x, y = move(line, x, y)
            rtn += decode(x, y)
    return rtn

if __name__ == "__main__":
    print(run())
