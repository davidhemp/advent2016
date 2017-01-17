import unittest

from python import part1 as d17p1
from python import part2 as d17p2

class TestDay17(unittest.TestCase):
    def test_part1(self):
        test_str = "hijkl"
        assert_str = "UDL"
        self.assertEqual(d17p1.doors(test_str), assert_str)
        self.assertEqual(d17p1.move(test_str), False)
        self.assertEqual(d17p1.move("ihgpwlah"), "ihgpwlahDDRRRD")
        self.assertEqual(d17p1.move("kglvqrro"), "kglvqrroDDUDRLRRUDRD")
        self.assertEqual(d17p1.move("ulqzkmiv"),
                            "ulqzkmivDRURDRUDDLLDLUURRDULRLDUUDDDRR")

    def test_part1(self):
        self.assertEqual(d17p2.run("ihgpwlah"), 370)
        self.assertEqual(d17p2.run("kglvqrro"), 492)
        self.assertEqual(d17p2.run("ulqzkmiv"), 830)

    def test_answers(self):
        self.assertEqual(d17p1.run("pgflpeqp"), "RDRLDRDURD")
        self.assertEqual(d17p2.run("pgflpeqp"), 596)


def main():
    unittest.main()

if __name__ == "__main__":
    main()
