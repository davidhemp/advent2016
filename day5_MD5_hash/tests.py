import unittest

from python import part1 as d5p1
from python import part2 as d5p2

# md5 hashs takes a while in python
class TestDay5(unittest.TestCase):
    def test_part1(self):
        input_string = "abc5017308"
        self.assertEqual(d5p1.hash(input_string), "000008f82")
        assert_keys = [3231929, 5017308, 5278568, 5357525,
                5708769, 6082117, 8036669, 8605828]
        password, test_keys = d5p1.run("abc")
        self.assertEqual(password, "18f47a30")
        self.assertEqual(len(assert_keys), len(test_keys))
        for a,b in zip(assert_keys, test_keys):
            self.assertEqual(a, b)

    def test_part2(self):
        input_string = "abc5017308"
        self.assertEqual(d5p2.hash(input_string), "000008f82")
        assert_keys = [3231929, 5357525, 5708769, 8036669,
        8605828, 8609554, 13666005, 13753421]
        password, test_keys = d5p2.run("abc")
        self.assertEqual(password, "05ace8e3")
        self.assertEqual(len(assert_keys), len(test_keys))
        for a,b in zip(test_keys, assert_keys):
            self.assertEqual(a, b)

    #To check that any future changes still give the now known solution
    def test_answers(self):
        self.assertEqual(d1p1.run("uqwqemis")[0], "1a3099aa")
        self.assertEqual(d1p2.run("uqwqemis")[0], "694190cd")


def main():
    unittest.main()

if __name__ == "__main__":
    main()
