def run(filename = "input.txt"):
    letters = [[] for i in range(8)]
    with open(filename) as f:
        for line in f:
            for c,e in zip(line.strip(), letters):
                e.append(c)

    final_word = ""
    for col in letters:
        letter_set = set(col)
        old_count = 1000
        for l in letter_set:
            new_count = col.count(l)
            if new_count < old_count:
                f_l = l
                old_count = new_count
        final_word += f_l
    return final_word

if __name__ == "__main__":
    print(run())
