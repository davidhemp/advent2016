def run():
    inputString = "L1, R3, R1, L5, L2, L5, R4, L2, R2, R2, L2, R1, L5, R3, L4, L1, L2, R3, R5, L2, R5, L1, R2, L5, R4, R2, R2, L1, L1, R1, L3, L1, R1, L3, R5, R3, R3, L4, R4, L2, L4, R1, R1, L193, R2, L1, R54, R1, L1, R71, L4, R3, R191, R3, R2, L4, R3, R2, L2, L4, L5, R4, R1, L2, L2, L3, L2, L1, R4, R1, R5, R3, L5, R3, R4, L2, R3, L1, L3, L3, L5, L1, L3, L3, L1, R3, L3, L2, R1, L3, L1, R5, R4, R3, R2, R3, L1, L2, R4, L3, R1, L1, L1, R5, R2, R4, R5, L1, L1, R1, L2, L4, R3, L1, L3, R5, R4, R3, R3, L2, R2, L1, R4, R2, L3, L4, L2, R2, R2, L4, R3, R5, L2, R2, R4, R5, L2, L3, L2, R5, L4, L2, R3, L5, R2, L1, R1, R3, R3, L5, L2, L2, R5"

    steps = []
    for step in inputString.split(' '):
        steps.append(step.strip(','))

    coords = [0, 0, 0, 0]
    visited = []
    direction = 0

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
            visited.append([coords[0] - coords[2], coords[1] - coords[3]])

    i = 0
    crossings = []
    for test_point in visited[1:]:
        for step in visited[:i]:
            if test_point == step:
                crossings.append(test_point)
        i += 1

    x = crossings[0][0]
    y = crossings[0][1]
    print("First crossing @ ")
    print("X: %i\n Y: %i\nTotal distance: %i" %(x, y, abs(x) + abs(y)))

    x = coords[0] - coords[2]
    y = coords[1] - coords[3]
    print("Final position @")
    print("X: %i\n Y: %i\nTotal distance: %i" %(x, y, abs(x) + abs(y)))
