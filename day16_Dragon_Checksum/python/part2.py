def shuffle(a):
    b = []
    for i in reversed(a):
        b.append((abs(int(i)-1)))
    return a+[0]+b

def checksum(a):
    b = []
    while len(b)%2 == 0:
        b = []
        for i,j in zip(a[::2], a[1::2]):
            if i == j:
                b.append(1)
            else:
                b.append(0)
        a=b
    return b

def run(puzzle_input = "11110010111001001", length=35651584):
    input_list = [int(i) for i in puzzle_input]
    while len(input_list)< length:
        input_list = shuffle(input_list)
    return checksum(input_list[:length])


if __name__ == "__main__":
    print("".join(str(i) for i in run()))
