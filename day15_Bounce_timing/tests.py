import os
import unittest

from python import part1 as d15p1
from python import part2 as d15p2

# md5 hashs takes a while in python
class TestDay15(unittest.TestCase):
    def __init__(self, args):
        super(TestDay15, self).__init__(args)
        if "day15_Bounce_timing" in os.getcwd():
            self.path = "python/"
        else:
            self.path = "day15_Bounce_timing/python/"

    def test_part1(self):
            self.assertEqual(d15p1.run(self.path+"testinput.txt"), 5)

    # def test_part2(self):
    #         self.assertEqual(d15p2.run(self.path+"testinput.txt"), 5)

    #To check that any future changes still give the now known solution
    def test_answers(self):
        self.assertEqual(d15p1.run(self.path+"input.txt"), 376777)
        self.assertEqual(d15p2.run(self.path+"input.txt"), 3903937)

def main():
    unittest.main()

if __name__ == "__main__":
    main()
