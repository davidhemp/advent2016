import unittest

from python import part1 as d24p1
from python import part2 as d24p2

# md5 hashs takes a while in python
class TestDay24(unittest.TestCase):
    def setUp(self):
        import os
        if "day24_Traveling_salesman" in os.getcwd():
            self.path = "python/"
        else:
            self.path = "day24_Traveling_salesman/python/"
        with open(self.path + "testinput.txt") as f:
            self.test_maze = [list(line.strip()) for line in f]

    def test_part1_allowed_moves(self):
        self.assertEqual(d24p1.allowed_moves(self.test_maze, 1, 3),
                         [[1, 2], [1, 4]])
        self.assertEqual(d24p1.allowed_moves(self.test_maze, 1, 1),
                         [[2, 1], [1, 2]])

    def test_part1_bfs(self):
        assert_dict = {1: 2, 3: 10, 2: 8, 4: 2}
        self.assertEqual(d24p1.bfs(self.test_maze, 1, 1), assert_dict)

    def test_part1_node_locations(self):
        assert_dict = {0:[1, 1], 1: [1, 3], 3: [3, 9],
                       2: [1, 9], 4: [3, 1]}
        test_dict, rtn_maze = d24p1.node_locs(self.path + "testinput.txt")
        self.assertEqual(test_dict, assert_dict)
        self.assertEqual(rtn_maze, self.test_maze)

    def test_full_test(self):
        test_locations = {0:[1, 1], 1: [1, 3], 3: [3, 9],
                       2: [1, 9], 4: [3, 1]}
        assert_dict = {
                       0: {1: 2, 3: 10, 2: 8, 4: 2},
                       1: {0: 2, 3: 8, 2: 6, 4: 4},
                       2: {1: 6, 0: 8, 3: 2, 4: 10},
                       3: {1: 8, 0: 10, 2: 2, 4: 8},
                       4: {1: 4, 0: 2, 3: 8, 2: 10}
       }

        self.assertEqual(d24p1.find_edges(test_locations, self.test_maze),
                        assert_dict)
        self.assertEqual(d24p1.shortest_path(assert_dict), [14, (4,1,2,3)])
        self.assertEqual(d24p1.run(self.path + "testinput.txt"),
                        [14, (4,1,2,3)])


    #     To check that any future changes still give the now known solution
    def test_answers(self):
        self.assertEqual(d24p1.run(self.path + "input.txt"),
                        [430, (1, 7, 3, 6, 5, 2, 4)] )
        self.assertEqual(d24p2.run(self.path + "input.txt"),
                        [430, (1, 7, 3, 6, 5, 2, 4)] )

def main():
    unittest.main()

if __name__ == "__main__":
    main()
