def run():
    letters = [[] for i in range(8)]
    with open("input.txt") as f:
        for line in f:
            for c,e in zip(line.strip(), letters):
                e.append(c)

    old_count = 0
    final_word = ['-' for i in range(8)]
    for col,n in zip(letters, range(8)):
        letter_set = set(col)
        for l in letter_set:
            new_count = col.count(l)
            if new_count > old_count:
                final_word[n] = l
                old_count = new_count
        old_count = 0
    # print(final_word)
run()
