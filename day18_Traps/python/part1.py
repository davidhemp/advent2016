def generate(last_line):
    trap_matchs = ["^^.", ".^^", "^..", "..^"]
    last_line = '.' + last_line + '.'
    next_line = ''
    for i in xrange(len(last_line)-2):
        if last_line[i:i+3] in trap_matchs:
            next_line += '^'
        else:
            next_line += '.'
    return next_line

def run(puzzle_text="", i = 40):
    if puzzle_text == "":
        puzzle_text += ".^^..^...^..^^.^^^.^^^.^^^^^^.^.^^^^.^^.^^^^^^."
        puzzle_text += "^...^......^...^^^..^^^.....^^^^^^^^^....^^...^^^^..^"
    maze_map = []
    maze_map.append(puzzle_text)
    n = puzzle_text.count(".")
    i -= 1
    while i > 0:
        next_line = generate(maze_map[-1])
        maze_map.append(next_line)
        n += next_line.count(".")
        i -= 1
    return maze_map, n

if __name__ == "__main__":
    maze_map, n = run()
    print("There are %i safe tiles" %n)
    # for m in maze_map:
    #     print(m)
