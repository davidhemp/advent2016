import os
import unittest

from python import part1 as d6p1
from python import part2 as d6p2

# md5 hashs takes a while in python
class TestDay6(unittest.TestCase):
    def __init__(self, args):
        super(TestDay6,self).__init__(args)
        if "day6_Rep_code" in os.getcwd():
            self.path = "python/"
        else:
            self.path = "day6_Rep_code/python/"

    def test_part1(self):
            self.assertEqual(d6p1.run(self.path+"testinput.txt")[:6], "easter")

    def test_part2(self):
            self.assertEqual(d6p2.run(self.path+"testinput.txt")[:6], "advent")

    #To check that any future changes still give the now known solution
    def test_answers(self):
        self.assertEqual(d6p1.run(self.path+"input.txt"), "umejzgdw")
        self.assertEqual(d6p2.run(self.path+"input.txt"), "aovueakv")
        
def main():
    unittest.main()

if __name__ == "__main__":
    main()
