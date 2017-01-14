import unittest

from python import part1 as d2p1
# from python import part2 as d2p2

class TestDay2(unittest.TestCase):
    def test_part1(self):
        input_string = ["ULL", "RRDDD", "LURDL", "UUUUD"]
        assert_string = "1985"
        self.assertEqual(d2p1.move(input_string), assert_string)

    #To check that any future changes still give the now known solution
    def test_answers(self):
        import os
        if "day2" in os.getcwd():
            path = "python/"
        else:
            path = "day2_Keypad/python/"
        self.assertEqual(d2p1.run(path=path), "47978")
    # def test_part2(self):
    #     input_string = "101 301 501\n102 302 502\n103 303 503\n"
    #     input_string += "201 401 601\n202 402 602\n203 403 603\n"
    #     self.assertEqual(d3p2.count(input_string), 6)
    #     input_string = "01 01 01\n102 302 502\n103 303 503\n"
    #     input_string += "01 01 01\n202 402 602\n203 403 603\n"
    #     self.assertEqual(d3p2.count(input_string), 0)
    #
    # def test_answers(self):
    #     import os
    #     if "day3_Triangles" in os.getcwd():
    #         path = "python/"
    #     else:
    #         path = "day3_Triangles/python/"
    #     self.assertEqual(d3p1.run(path=path), 983)
    #     self.assertEqual(d3p2.run(path=path), 1836)

def main():
    unittest.main()

if __name__ == "__main__":
    main()
