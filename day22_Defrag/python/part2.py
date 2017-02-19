def run(path = ""):
    lines = open(path + "input.txt").readlines()
    data = []
    for i in range(2, len(lines), 25):
        data.append(lines[i:i+25])
    test_line = data[10][10]
    print(test_line)
    for i, j in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
        print(data[10+i][10+j].strip())

if __name__ == "__main__":
    print(run())
