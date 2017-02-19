import unittest
import os

from python import part1 as d21p1
from python import part2 as d21p2

class TestDay21(unittest.TestCase):
    def __init__(self, args):
        super(TestDay21, self).__init__(args)
        if "day21_Cypher" in os.getcwd():
            self.path = "python/"
        else:
            self.path = "day21_Cypher/python/"

    def test_part1_operations(self):
        test_list = [i for i in "abcde"]
        asserts = ["ebcda", "edcba", "abcde", "bcdea",
                    "bdeac", "abdec", "ecabd", "decab"]
        data = open(self.path + "testinput.txt").readlines()
        for test_operation, assert_str in zip(data, asserts):
            test_list = d21p1.operation(test_list, test_operation)
            test_str = "".join(test_list)
            self.assertEqual(test_str, assert_str)

    def test_part2_operations(self):
        test_list = [i for i in "decab"]
        asserts = ["ecabd", "abdec", "bdeac", "bcdea",
                    "abcde", "edcba", "ebcda", "abcde"]
        data = open(self.path + "testinput.txt").readlines()
        for test_operation, assert_str in zip(data[::-1], asserts):
            test_list = d21p2.operation(test_list, test_operation)
            test_str = "".join(test_list)
            self.assertEqual(test_str, assert_str)

    def test_answers(self):
        self.assertEqual(d21p1.run(self.path), "dgfaehcb")
        self.assertEqual(d21p2.run(self.path), "fdhgacbe")

def main():
    unittest.main()

if __name__ == "__main__":
    main()
