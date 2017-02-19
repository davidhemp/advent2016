import unittest

from python import part1 as d11p1
# from python import part2 as d10p2

# md5 hashs takes a while in python
class TestDay11(unittest.TestCase):
    def setUp(self):
        import os
        if "day11_ChipGen_BFS" in os.getcwd():
            self.path = "python/"
        else:
            self.path = "day11_ChipGen_BFS/python/"

    def test_make_pair(self):
        self.assertEqual(d11p1.make_pair("LM"), "LG")
        self.assertEqual(d11p1.make_pair("LG"), "LM")

    def test_missing_pairs(self):
        test_list = ["LM", "LG", "CM"]
        assert_list = ["CM"]
        self.assertEqual(d11p1.find_unpaired(test_list), assert_list)

    def test_allowed_states(self):
        test_list = [["LM", "HM"], ["HG"], ["LG"], [], 0]
        assert_list = [[['LM'], ['HG', 'HM'], ['LG'], [], 1]]
        self.assertEqual(d11p1.allowed_states(test_list), assert_list)
        test_list = [["LM", "HM"], [], ["LG", "HG"], [], 0]
        assert_list = [[['HM'], ['LM'], ['LG', 'HG'], [], 1],
                        [['LM'], ['HM'], ['LG', 'HG'], [], 1]]
        self.assertEqual(d11p1.allowed_states(test_list), assert_list)

    def test_full(self):
        self.assertEqual(d11p1.run(True), 11)
def main():
    unittest.main()

if __name__ == "__main__":
    main()
