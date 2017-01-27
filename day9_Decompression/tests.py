import unittest

from python import part1 as d9p1
from python import part2 as d9p2

# md5 hashs takes a while in python
class TestDay9(unittest.TestCase):

    def test_part1(self):
        self.assertEqual(d9p1.decompress("A(1x5)BC"), "ABBBBBC")
        self.assertEqual(d9p1.decompress("(3x3)XYZ"), "XYZXYZXYZ")
        self.assertEqual(d9p1.decompress("A(2x2)BCD(2x2)EFG"),
                                         "ABCBCDEFEFG")
        self.assertEqual(d9p1.decompress("(6x1)(1x3)A"), "(1x3)A")
        self.assertEqual(d9p1.decompress("X(8x2)(3x3)ABCY"),
                                         "X(3x3)ABC(3x3)ABCY")

    def test_part2(self):
        self.assertEqual(d9p2.decompress("(3x3)XYZ"), len("XYZXYZXYZ"))
        self.assertEqual(d9p2.decompress("X(8x2)(3x3)ABCY"),
                                         len("XABCABCABCABCABCABCY"))
        self.assertEqual(d9p2.decompress("(27x12)(20x12)(13x14)(7x10)(1x12)A"),
                                         241920)
        input_str = "(25x3)(3x3)ABC(2x3)XY(5x2)PQRSTX(18x9)(3x2)TWO(5x7)SEVEN"
        self.assertEqual(d9p2.decompress(input_str), 445)

    #To check that any future changes still give the now known solution
    def test_answers(self):
        import os
        if "day9_Decompression" in os.getcwd():
            path = "python/"
        else:
            path = "day9_Decompression/python/"
        self.assertEqual(d9p1.run(path + "input.txt"), 74532)
        # self.assertEqual(d8p2.run(path), 260)


def main():
    unittest.main()

if __name__ == "__main__":
    main()
