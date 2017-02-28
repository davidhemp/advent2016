import math

class LinkedList(object):
    def __init__(self, id):
        self.id = id
        self.right_player = None
        self.left_player = None

    def remove(self):
        self.left_player.right_player = self.right_player
        self.right_player.left_player = self.left_player

def propagate(no_players=5):
    players = map(LinkedList, xrange(no_players))
    for i in xrange(no_players):
        players[i].left_player = players[(i+1)%no_players]
        players[i].right_player = players[(i-1)%no_players]
    start = players[0]
    opposite_player = players[no_players/2]
    for i in xrange(no_players):
        opposite_player.remove()
        opposite_player = opposite_player.left_player
        if (no_players-i)%2 == 1:
            opposite_player = opposite_player.left_player
        start = start.left_player
    return start.id+1

def run(input=3004953):
    return propagate(3004953)

if __name__ == "__main__":
    print(run())
