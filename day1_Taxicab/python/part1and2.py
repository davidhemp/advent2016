def move(steps):
    coords = [0, 0, 0, 0]
    visited = []
    direction = 0
    crossings = []
    for step in steps:
        if step[0] == 'L':
            direction -= 1
        else:
            direction += 1
        if direction < 0:
            direction = 3
        elif direction > 3:
            direction = 0
        for i in range(int(step[1:])):
            coords[direction] += 1
            x = coords[0] - coords[2]
            y = coords[1] - coords[3]
            if [x,y] not in visited:
                visited.append([x, y])
            else:
                crossings.append([x, y])
    x = coords[0] - coords[2]
    y = coords[1] - coords[3]
    final_position = abs(x) + abs(y)
    try:
        first_crossing = abs(crossings[0][0]) + abs(crossings[0][1])
    except IndexError:
        first_crossing = -1
    return final_position, first_crossing

def run(path=""):
    with open(path + "input.txt") as f:
        steps = f.readline().strip().split(", ")
    final_position, first_crossing = move(steps)
    # print("First crossing is %i away" %first_crossing)
    # print("Final position is %i away" %final_position)
    return final_position, first_crossing
