import copy
from itertools import permutations

def allowed_moves(maze, y, x):
    """Simply looks for walls as everything else is passable"""
    allowed = []
    # display(maze, y, x)
    for i in [-1, 1]:
        if maze[y+i][x] is not '#':
            allowed.append([y+i, x])
        if maze[y][x+i] is not '#':
            allowed.append([y, x+i])
    return allowed

def bfs(maze, y, x):
    """Returns the distances from the start to the other points of interest"""
    frontier = [[y,x]]
    level = 1
    visited = dict()
    visited["%i,%i" %(y,x)] = 1
    points = dict()
    while frontier:
        nxt = []
        for coords in frontier:
            for move in allowed_moves(maze, *coords):
                str_move = "%i,%i" %(move[0], move[1])
                if str_move not in visited:
                    if maze[move[0]][move[1]] is not '.':
                        points[int(maze[move[0]][move[1]])] = level
                    visited[str_move] = level
                    nxt.append(move)
        frontier = nxt
        level += 1
    return points

def node_locs(filename):
    """Loads the maze data but also checks for the important locations """
    maze = []
    x = y = 0
    i = j = 0
    node_locations = dict()
    for line in open(filename):
        maze.append(list(line.strip()))
        for p in range(9):
            if str(p) in line:
                node_locations[p] = [j, line.index(str(p))]
        j += 1
    return node_locations, maze

def find_edges(node_locations, maze):
    """ Calls bfs from each of the important locations to get the edges"""
    edges = dict()
    for node, coords in node_locations.iteritems():
        distances = dict()
        for dest, distance in bfs(maze, coords[0], coords[1]).iteritems():
            distances[dest] = distance
        edges[node] = distances
    return edges

def shortest_path(edges):
    """Uses permutations to find the shortest path. As all nodes can reach all
    other nodes we don't have to do a search as such. Also the nodes connected
    to node 0 is also the complete node list"""
    rtn = []
    starting_node = 0
    for path in permutations(edges[starting_node].keys()):
        current_path = 0
        current_node = starting_node
        for node in path:
            current_path += edges[current_node][node]
            current_node = node
        current_path += edges[current_node][0]
        rtn.append([current_path, path])
    return min(rtn)

def run(filename="input.txt"):
    node_locations, maze = node_locs(filename)
    edges = find_edges(node_locations, maze)
    return shortest_path(edges)

def display(maze, y, x):
    display_maze = copy.deepcopy(maze)
    display_maze[y][x] = '*'
    for l in display_maze:
        print("".join(l))
    print("")

if __name__ == "__main__":
    print(run())
