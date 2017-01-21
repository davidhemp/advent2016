import unittest

from python import part1 as d12p1
from python import part2 as d12p2

# md5 hashs takes a while in python
class TestDay12(unittest.TestCase):
    def setUp(self):
        import os
        if "day12_ASM" in os.getcwd():
            self.path = "python/"
        else:
            self.path = "day12_ASM/python/"

    def test_parts(self):
        self.assertEqual(d12p1.run(self.path + "testinput.txt"), 42)
        self.assertEqual(d12p2.run(self.path + "testinput.txt"), 42)

    #To check that any future changes still give the now known solution
    def test_answers(self):
        self.assertEqual(d12p1.run(self.path + "input.txt"), 318020)
        self.assertEqual(d12p2.run(self.path + "input.txt"), 9227674)

def main():
    unittest.main()

if __name__ == "__main__":
    main()
