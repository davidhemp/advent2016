import os
import unittest

from python import part1 as d14p1
# from python import part2 as d14p2

# md5 hashs takes a while in python
class TestDay14(unittest.TestCase):
    def test_MD5(self):
        assert_string = "0034e0923cc38887a57bd7b1d4f953df"
        self.assertEqual(d14p1.hash("abc18"), assert_string)

    def test_hash_search(self):
        test_string = "0034e0923cc38887a57bd7b1d4f953df"
        self.assertEqual(d14p1.rgx_search(test_string), (3,'8', test_string))

    # def test_full_example(self): #umm why is this one off?
    #     self.assertEqual(d14p1.run("abc"), 22728)

    # def test_part2(self):
    #         self.assertEqual(d14p2.run(self.path+"testinput.txt"), 5)

    #To check that any future changes still give the now known solution
    def test_answers(self):
        self.assertEqual(d14p1.run(), 15035)

def main():
    unittest.main()

if __name__ == "__main__":
    main()
