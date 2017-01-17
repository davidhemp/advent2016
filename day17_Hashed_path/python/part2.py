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
    level = 1
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
                        longest = level
                        del next_level[s+d]
                except KeyError:
                    pass
        frontier = next_level
        level += 1
    return longest

def run(puzzle_input = "pgflpeqp"):
    return move(puzzle_input)

if __name__ == "__main__":
    print(run())
