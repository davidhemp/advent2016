import unittest

from python import part1 as d19p1
from python import part2 as d19p2

class TestDay19(unittest.TestCase):

    def test_part1_propagate(self):
        self.assertEqual(d19p1.propagate(5), 3)
        self.assertEqual(d19p1.propagate(11), 7)
        self.assertEqual(d19p1.propagate(13), 11)
        self.assertEqual(d19p1.propagate(9), 3)

    def test_part2_full(self):
        self.assertEqual(d19p2.propagate(5), 2)

    def test_answers(self):
        self.assertEqual(d19p1.run(3004953), 1815603)
        self.assertEqual(d19p2.run(3004953), 1410630)

def main():
    unittest.main()

if __name__ == "__main__":
    main()
