import unittest

from python import part1 as d7p1
from python import part2 as d7p2

# md5 hashs takes a while in python
class TestDay7(unittest.TestCase):
    def test_part1(self):
        input_strings = ["abba[mnop]qrst", "abcd[bddb]xyyx",
                            "aaaa[qwer]tyui", "ioxxoj[asdfgh]zxcvbn"]
        asserts = [1, 0, 0,1]
        for t, a in zip(input_strings, asserts):
            self.assertEqual(d7p1.search_line(t), a)

    def test_part2(self):
        input_strings = ["aba[bab]xyz", "xyx[xyx]xyx",
                            "aaa[kek]eke", "zazbz[bzb]cdb"]
        asserts = [1, 0, 1, 1]
        for t, a in zip(input_strings, asserts):
            self.assertEqual(d7p2.search_line(t), a)

    #To check that any future changes still give the now known solution
    def test_answers(self):
        import os
        if "day7_TLS_SSL" in os.getcwd():
            path = "python/"
        else:
            path = "day7_TLS_SSL/python/"
        self.assertEqual(d7p1.run(path), 118)
        self.assertEqual(d7p2.run(path), 260)


def main():
    unittest.main()

if __name__ == "__main__":
    main()
