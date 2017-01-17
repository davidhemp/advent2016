import hashlib

def doors(path_string):
    open_doors = ""
    path_hash = hashlib.md5(path_string).hexdigest()[:4]
    for c,d in zip(path_hash, ['U', 'D', 'L', 'R']):
        if int(c, 16) > 10:
            open_doors += d
    return open_doors

def move(puzzle_input):
    x = y = 0
    frontier = {puzzle_input: [x,y]}
    while (len(frontier) != 0):
        next_level = dict()
        for s, pos in frontier.iteritems():
            for d in doors(s):
                if d == 'U' and (pos[1] - 1) > -1:
                    next_level[s + d] = [pos[0], pos[1] - 1]
                if d == 'D' and (pos[1] + 1) < 4:
                    next_level[s + d] = [pos[0], pos[1] + 1]
                if d == 'L' and (pos[0] - 1) > -1:
                    next_level[s + d] = [pos[0] - 1, pos[1]]
                if d == 'R' and (pos[0] + 1) < 4:
                    next_level[s + d] = [pos[0] + 1, pos[1]]
                try:
                    if next_level[s+d] == [3,3]:
                        return (s+d)
                except KeyError:
                    pass
        frontier = next_level
    return False

def run(puzzle_input = "pgflpeqp"):
    rtn = move(puzzle_input)
    if rtn:
        return rtn.split(puzzle_input)[1]

if __name__ == "__main__":
    print(run())
