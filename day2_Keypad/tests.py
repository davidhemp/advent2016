import unittest

from python import part1 as d2p1
from python import part2 as d2p2

class TestDay2(unittest.TestCase):
    def test_part1(self):
        input_string = ["ULL", "RRDDD", "LURDL", "UUUUD"]
        assert_string = "1985"
        self.assertEqual(d2p1.move(input_string), assert_string)

    def test_part2(self):
        input_string = ["ULL", "RRDDD", "LURDL", "UUUUD"]
        assert_list = [[1, 3], [3, 5], [3, 4], [3, 2]]
        assert_string = "5DB3"
        x = 1
        y = 3
        test_list = []
        for i in input_string:
            x, y = d2p2.move(i, x, y)
            test_list.append([x,y])
        self.assertEqual(str(test_list), str(assert_list))

    #To check that any future changes still give the now known solution
    def test_answers(self):
        import os
        if "day2" in os.getcwd():
            path = "python/"
        else:
            path = "day2_Keypad/python/"
        self.assertEqual(d2p1.run(path=path), "47978")
        self.assertEqual(d2p2.run(path=path), "659AD")


def main():
    unittest.main()

if __name__ == "__main__":
    main()
