import re
import os
from time import sleep

def rect(line, grid):
    m = re.search(r"rect (\d+)x(\d+)", line.strip())
    for i in range(int(m.group(2))):
        for j in range(int(m.group(1))):
            grid[i][j] = "#"
    return grid

def rotate(line, grid):
    m = re.match(r"rotate (column|row) (x|y)=(\d+) by (\d+)", line.strip())
    if m.group(2) == "y":
        for _ in range(int(m.group(4))):
            row = int(m.group(3))
            last_char = grid[row][-1]
            for i in range(len(grid[row])-1, 0, -1):
                grid[row][i] = grid[row][i-1]
            grid[row][0] = last_char
    elif m.group(2) == "x":
        for _ in range(int(m.group(4))):
            col = int(m.group(3))
            last_char = grid[-1][col]
            for i in range(len(grid)-1, 0, -1):
                grid[i][col] = grid[i-1][col]
            grid[0][col] = last_char
    else:
        raise(ValueError("Missing x/y"))
    return grid

def display(grid):
    os.system("clear")
    for l in grid:
        print("".join(i for i in l))

def run(filename = "input.txt"):
    grid = [['.' for x in range(50)] for i in range(6)]
    with open(filename) as f:
        for line in f.readlines():
            if "rect" in line:
                grid = rect(line, grid)
            else:
                grid = rotate(line, grid)
            # display(grid)
            # sleep(0.05)
    n = 0
    for l in grid:
        for i in l:
            if i == '#':
                n += 1
    return (n, grid)

if __name__ == "__main__":

    print(run()[0])
