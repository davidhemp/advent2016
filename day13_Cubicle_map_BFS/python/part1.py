def space_check(input_number, x, y):
    z = x*x + 3*x + 2*x*y + y + y*y + input_number
    return bin(z)[2:].count('1')%2 == 0

def bfs(input_number, target):
    frontier = [[1,1]]
    last_frontier = []
    level = 0
    while target not in frontier and len(frontier) > 0:
        next_frontier = []
        for x,y in frontier:
            if x-1 >= 0 and space_check(input_number, x-1, y):
                if [x-1,y] not in last_frontier:
                    next_frontier.append([x-1,y])
            if y-1 >= 0 and space_check(input_number, x, y-1):
                if [x,y-1] not in last_frontier:
                    next_frontier.append([x,y-1])
            if space_check(input_number, x+1, y):
                if [x+1,y] not in last_frontier:
                    next_frontier.append([x+1,y])
            if space_check(input_number, x, y+1):
                if [x,y+1] not in last_frontier:
                    next_frontier.append([x,y+1])
        last_frontier = frontier
        frontier = next_frontier
        level += 1
    return level

def run():
    return bfs(1352, [31,39])

if __name__ == "__main__":
    print(run())
