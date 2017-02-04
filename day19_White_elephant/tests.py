import unittest

from python import part1 as d19p1
# from python import part2 as d19p2

class TestDay19(unittest.TestCase):

    def test_part1_propagate(self):
        self.assertEqual(d19p1.propagate(5), 3)
        self.assertEqual(d19p1.propagate(11), 7)
        self.assertEqual(d19p1.propagate(13), 11)
        self.assertEqual(d19p1.propagate(9), 3)

    # def test_answers(self):
    #     input_str = ".^^..^...^..^^.^^^.^^^.^^^^^^.^.^^^^.^^.^^^^^^."
    #     input_str += "^...^......^...^^^..^^^.....^^^^^^^^^....^^...^^^^..^"
    #     maze_map, test_int = d19p1.run(input_str, 40)
    #     self.assertEqual(test_int, 2005)
    #     self.assertEqual(d18p2.run(i = 400000), 20008491)

def main():
    unittest.main()

if __name__ == "__main__":
    main()
