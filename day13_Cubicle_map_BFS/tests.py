import unittest

from python import part1 as d13p1
from python import part2 as d13p2

# md5 hashs takes a while in python
class TestDay13(unittest.TestCase):
    def test_space_check(self):
        self.assertEqual(d13p1.space_check(10, 5, 1), False)
        self.assertEqual(d13p1.space_check(10, 2, 4), False)
        self.assertEqual(d13p1.space_check(10, 5, 3), True)
        self.assertEqual(d13p1.space_check(10, 7, 0), True)
        self.assertEqual(d13p1.space_check(10, 1, 1), True)
        self.assertEqual(d13p1.space_check(10, 1, 2), True)
        # self.assertEqual(d13p2.run(self.path + "testinput.txt"), 42)
    def test_gfs(self):
        self.assertEqual(d13p1.bfs(10, [7,4]), 11)

    #To check that any future changes still give the now known solution
    def test_answers(self):
        self.assertEqual(d13p1.run(), 90)
        self.assertEqual(d13p2.run(), 135)

def main():
    unittest.main()

if __name__ == "__main__":
    main()
