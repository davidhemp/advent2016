import unittest
import os

from python import part1 as d22p1
# from python import part2 as d22p2

class TestDay22(unittest.TestCase):
    def __init__(self, args):
        super(TestDay22, self).__init__(args)
        if "day22_Defrag" in os.getcwd():
            self.path = "python/"
        else:
            self.path = "day22_Defrag/python/"

    def test_part1(self):
        self.assertEqual(d22p1.run(self.path + "testinput.txt"), 7)

    def test_answers(self):
        self.assertEqual(d22p1.run(self.path + "input.txt"), 901)

def main():
    unittest.main()

if __name__ == "__main__":
    main()
