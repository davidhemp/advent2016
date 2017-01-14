import unittest

from python import part1 as d16p1

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
