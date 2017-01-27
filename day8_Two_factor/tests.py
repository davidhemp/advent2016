import unittest

from python import part1 as d8p1

# md5 hashs takes a while in python
class TestDay8(unittest.TestCase):
    def test_part1_rect(self):
        grid = [['.' for i in range(7)] for j in range(3)]
        input_string = "rect 3x2"
        assert_string = "###....\n###....\n.......\n"
        test_grid = ""
        for i in d8p1.rect(input_string, grid):
            temp_string = "".join(j for j in i)
            test_grid += temp_string + "\n"
        self.assertEqual(test_grid, assert_string)

    def test_part1_rotate_column(self):
        grid_string = "1234567\n89ABCDE\nFGHIJKL"
        grid = [list(i) for i in grid_string.split('\n')]
        input_string = "rotate column x=2 by 1"
        assert_string = "12H4567\n893BCDE\nFGAIJKL\n"
        test_grid = "" #there must be a way to do this in one line..
        for i in d8p1.rotate(input_string, grid):
            temp_string = "".join(j for j in i)
            test_grid += temp_string + "\n"
        self.assertEqual(test_grid, assert_string)

    def test_part1_rotate_row(self):
        grid_string = "1234567\n89ABCDE\nFGHIJKL"
        grid = [list(i) for i in grid_string.split('\n')]
        input_string = "rotate row y=0 by 4"
        assert_string = "4567123\n89ABCDE\nFGHIJKL\n"
        test_grid = "" #there must be a way to do this in one line..
        for i in d8p1.rotate(input_string, grid):
            temp_string = "".join(j for j in i)
            test_grid += temp_string + "\n"
        self.assertEqual(test_grid, assert_string)

    #To check that any future changes still give the now known solution
    def test_answers(self):
        import os
        if "day8_Two_factor" in os.getcwd():
            path = "python/"
        else:
            path = "day8_Two_factor/python/"
        self.assertEqual(d8p1.run(path + "input.txt")[0], 110)
        # self.assertEqual(d8p2.run(path), 260)


def main():
    unittest.main()

if __name__ == "__main__":
    main()
