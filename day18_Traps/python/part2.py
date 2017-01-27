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

def run(puzzle_text="", i = 400000):
    if puzzle_text == "":
        puzzle_text += ".^^..^...^..^^.^^^.^^^.^^^^^^.^.^^^^.^^.^^^^^^."
        puzzle_text += "^...^......^...^^^..^^^.....^^^^^^^^^....^^...^^^^..^"
    last_line = puzzle_text
    n = puzzle_text.count(".")
    i -= 1
    while i > 0:
        next_line = generate(last_line)
        n += next_line.count(".")
        last_line = next_line
        i -= 1
    return n

if __name__ == "__main__":
    n = run(i=400000)
    print("There are %i safe tiles" %n)
