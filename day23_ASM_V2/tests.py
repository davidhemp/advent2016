import unittest

from python import part1 as d23p1
# from python import part2 as d23p2

# md5 hashs takes a while in python
class TestDay23(unittest.TestCase):
    def setUp(self):
        import os
        if "day23_ASM_V2" in os.getcwd():
            self.path = "python/"
        else:
            self.path = "day23_ASM_V2/python/"

    def test_parts(self):
        self.assertEqual(d23p1.run(self.path + "testinput1.txt"), 42)
        self.assertEqual(d23p1.run(self.path + "testinput2.txt"), 3)
        # self.assertEqual(d23p2.run(self.path + "testinput.txt"), 42)

        # To check that any future changes still give the now known solution
    def test_answers(self):
        self.assertEqual(d23p1.run(self.path + "input.txt"), 318020)
        # self.assertEqual(d23p2.run(self.path + "input.txt"), 9227674)

def main():
    unittest.main()

if __name__ == "__main__":
    main()
