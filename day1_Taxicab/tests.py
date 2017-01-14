import unittest

from python import part1and2 as d1p1n2
# from python import part2 as d2p2

class TestDay1(unittest.TestCase):
    def test_part1(self):
        input_list = ["R5", "L5", "R5", "R3"]
        assert_int = 12
        self.assertEqual(d1p1n2.move(input_list)[0], assert_int)
        input_list = ["R8", "R4", "R4", "R8"]
        assert_int = 4
        self.assertEqual(d1p1n2.move(input_list)[1], assert_int)

    #To check that any future changes still give the now known solution
    def test_answers(self):
        import os
        if "day1" in os.getcwd():
            path = "python/"
        else:
            path = "day1_Taxicab/python/"
        final_position, first_crossing = d1p1n2.run(path=path)
        self.assertEqual(final_position, 278)
        self.assertEqual(first_crossing, 161)

def main():
    unittest.main()

if __name__ == "__main__":
    main()
