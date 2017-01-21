def space_check(input_number, x, y):
    z = x*x + 3*x + 2*x*y + y + y*y + input_number
    return bin(z)[2:].count('1')%2 == 0

def bfs(input_number, target):
    frontier = [[1,1]]
    locations = []
    level = 0
    while level != target and len(frontier) > 0:
        next_frontier = []
        for x,y in frontier:
            if x-1 >= 0 and space_check(input_number, x-1, y):
                if [x-1,y] not in locations:
                    next_frontier.append([x-1,y])
                    locations.append([x-1,y])
            if y-1 >= 0 and space_check(input_number, x, y-1):
                if [x,y-1] not in locations:
                    next_frontier.append([x,y-1])
                    locations.append([x,y-1])
            if space_check(input_number, x+1, y):
                if [x+1,y] not in locations:
                    next_frontier.append([x+1,y])
                    locations.append([x+1,y])
            if space_check(input_number, x, y+1):
                if [x,y+1] not in locations:
                    next_frontier.append([x,y+1])
                    locations.append([x,y+1])
        frontier = next_frontier
        level += 1
    return len(locations)

def run():
    return bfs(1352, 50)

if __name__ == "__main__":
    print(run())
