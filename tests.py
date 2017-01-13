import unittest

from day3_Triangles.python import part1 as d3p1
from day3_Triangles.python import part2 as d3p2
from day16_Dragon_Checksum.python import part1 as d16p1

class TestDay3(unittest.TestCase):
    def test_part1(self):
        self.assertEqual(d3p1.compare("23 26 50"), 0)
        self.assertEqual(d3p1.compare("23 27 50"), 0)
        self.assertEqual(d3p1.compare("23 28 50"), 1)

    def test_part2(self):
        input_string = "101 301 501\n102 302 502\n103 303 503\n"
        input_string += "201 401 601\n202 402 602\n203 403 603\n"
        self.assertEqual(d3p2.count(input_string), 6)
        input_string = "01 01 01\n102 302 502\n103 303 503\n"
        input_string += "01 01 01\n202 402 602\n203 403 603\n"
        self.assertEqual(d3p2.count(input_string), 0)

    #To check that any future changes still give the now known solution
    def test_answers(self):
        self.assertEqual(d3p1.run(path="day3_Triangles/python/"), 983)
        self.assertEqual(d3p2.run(path="day3_Triangles/python/"), 1836)

class TestDay16(unittest.TestCase):
    def test_part1_shuffle(self):
        test_strs = ["1", "0", "11111", "111100001010"]
        assert_strs =["100", "001", "11111000000","1111000010100101011110000"]
        for t,a in zip(test_strs, assert_strs):
            output = ""
            input_list = [int(i) for i in t]
            output = "".join(str(i) for i in d16p1.shuffle(input_list))
            self.assertEqual(output, a)

    def test_part1_checksum(self):
        test_str = "110010110100"
        input_list = [int(i) for i in test_str]
        output = "".join(str(i) for i in d16p1.checksum(input_list))
        self.assertEqual(output, "100")

    def test_part1_full_example(self):
        test_str = "10000"
        input_list = [int(i) for i in test_str]
        output = ""
        output = "".join(str(i) for i in d16p1.run(input_list, 20))
        self.assertEqual(output, "01100")

def main():
    unittest.main()

if __name__ == "__main__":
    main()
