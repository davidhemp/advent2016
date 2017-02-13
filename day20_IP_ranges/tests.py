import unittest
import os

from python import part1 as d20p1
from python import part2 as d20p2

class TestDay20(unittest.TestCase):
    def __init__(self, args):
        super(TestDay20, self).__init__(args)
        if "day20_IP_ranges" in os.getcwd():
            self.path = "python/"
        else:
            self.path = "day20_IP_ranges/python/"

    def test_part1_min_allowed(self):
        test_list = [[0, 2], [4,7], [5, 8]]
        self.assertEqual(d20p1.find_min(test_list), 3)

    def test_answers(self):
        self.assertEqual(d20p1.run(self.path), 22887907)
        self.assertEqual(d20p2.run(self.path), 20008491)

def main():
    unittest.main()

if __name__ == "__main__":
    main()
