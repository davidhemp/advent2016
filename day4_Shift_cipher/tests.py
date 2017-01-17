import unittest

from python import part1 as d4p1
from python import part2 as d4p2

class TestDay4(unittest.TestCase):
    def test_part1(self):
        input_strings = ["aaaaa-bbb-z-y-x-123[abxyz]",
                            "a-b-c-d-e-f-g-h-987[abcde]",
                            "not-a-real-room-404[oarel]",
                            "totally-real-room-200[decoy]"]
        asserts = [1, 1, 1, 0]
        for t, a in zip(input_strings, asserts):
            self.assertEqual(d4p1.search_line(t,0,0)[0], a)

    def test_part2(self):
        input_strings = ["aaaaa-bbb-z-y-x-123[abxyz]",
                            "a-b-c-d-e-f-g-h-987[abcde]",
                            "not-a-real-room-404[oarel]",
                            "totally-real-room-200[decoy]"]
        asserts = [1, 1, 1, 0]
        for t, a in zip(input_strings, asserts):
            self.assertEqual(d4p2.search_line(t,0)[0], a)
        self.assertEqual(d4p2.decode("qzmtzixmtkozyivhz", 343),
                                        "veryencryptedname")

    #To check that any future changes still give the now known solution
    def test_answers(self):
        import os
        if "day4_Shift_cipher" in os.getcwd():
            path = "python/"
        else:
            path = "day4_Shift_cipher/python/"
        self.assertEqual(d4p1.run(path)[1], 361724)
        self.assertEqual(int(d4p2.run(path)[1]), 482)


def main():
    unittest.main()

if __name__ == "__main__":
    main()
