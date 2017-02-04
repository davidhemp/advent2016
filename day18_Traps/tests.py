import unittest

from python import part1 as d18p1
from python import part2 as d18p2

class TestDay18(unittest.TestCase):

    def test_part1_generate(self):
        input_str = ".^^.^.^^^^"
        assert_str = "^^^...^..^"
        self.assertEqual(d18p1.generate(input_str), assert_str)
        input_str = "^^^^..^^^."
        assert_str = "^..^^^^.^^"
        self.assertEqual(d18p1.generate(input_str), assert_str)


    def test_part1_full_example(self):
        input_str = ".^^.^.^^^^"
        maze_map, test_int = d18p1.run(input_str, 10)
        self.assertEqual(test_int, 38)

    def test_answers(self):
        input_str = ".^^..^...^..^^.^^^.^^^.^^^^^^.^.^^^^.^^.^^^^^^."
        input_str += "^...^......^...^^^..^^^.....^^^^^^^^^....^^...^^^^..^"
        maze_map, test_int = d18p1.run(input_str, 40)
        self.assertEqual(test_int, 2005)
        self.assertEqual(d18p2.run(i = 400000), 20008491)


def main():
    unittest.main()

if __name__ == "__main__":
    main()
