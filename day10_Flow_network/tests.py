import unittest

from python import part1 as d10p1
# from python import part2 as d10p2

# md5 hashs takes a while in python
class TestDay10(unittest.TestCase):
    def setUp(self):
        import os
        if "day10_Flow_network" in os.getcwd():
            self.path = "python/"
        else:
            self.path = "day10_Flow_network/python/"

    def test_simple_network(self):
        outputs, _ = d10p1.run(self.path + "testinput.txt")
        zero = outputs[0].chips[0]
        one = outputs[1].chips[0]
        two = outputs[2].chips[0]
        self.assertEqual(zero, 5)
        self.assertEqual(one, 2)
        self.assertEqual(two, 3)
        self.assertEqual(zero*one*two, 30)

    #To check that any future changes still give the now known solution
    def test_answers(self):
        outputs, handover = d10p1.run(self.path + "input.txt")
        zero = outputs[0].chips[0]
        one = outputs[1].chips[0]
        two = outputs[2].chips[0]
        self.assertEqual(handover, 157)
        self.assertEqual(zero*one*two, 1085)

def main():
    unittest.main()

if __name__ == "__main__":
    main()
