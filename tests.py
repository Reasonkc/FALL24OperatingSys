import unittest
from boggle_solver import Boggle


class TestSuiteAlgScalabilityCases(unittest.TestCase):
    """Tests scalability and correctness of the Boggle solver."""

    def test_normal_case_3x3(self):
        grid = [["A", "B", "C"], ["D", "E", "F"], ["G", "H", "I"]]
        dictionary = ["abc", "abdhi", "abi", "ef", "cfi", "dea"]
        mygame = Boggle(grid, dictionary)
        solution = mygame.get_solution()
        expected = ["ABC", "ABDHI", "CFI", "DEA"]
        self.assertEqual(sorted(expected), sorted(solution))

    def test_normal_case_4x4(self):
        grid = [["T", "W", "Y", "R"],
                ["E", "N", "P", "H"],
                ["G", "Z", "Qu", "R"],
                ["O", "N", "T", "A"]]
        dictionary = ["art", "ego", "gent", "get", "net", "new", "newt",
                      "pry", "qua", "quart", "quartz", "rat", "tar", "tarp",
                      "ten", "went", "wet", "arty", "not", "quar", "prat"]
        mygame = Boggle(grid, dictionary)
        solution = mygame.get_solution()
        expected = ["ART", "EGO", "GENT", "GET", "NET", "NEW", "NEWT", "PRAT",
                    "PRY", "QUA", "QUART", "QUARTZ", "RAT", "TAR", "TARP",
                    "TEN", "WENT", "WET", "QUAR"]
        self.assertEqual(sorted(expected), sorted(solution))

    def test_7x7_grid(self):
        grid = [
            ["H", "A", "R", "B", "O", "R", "S"],
            ["T", "R", "A", "V", "E", "L", "S"],
            ["W", "I", "N", "T", "E", "R", "S"],
            ["S", "N", "O", "W", "F", "A", "L"],
            ["B", "R", "I", "S", "K", "S", "L"],
            ["C", "O", "L", "D", "S", "E", "A"],
            ["B", "E", "A", "C", "H", "S", "S"]
        ]
        dictionary = ["harbor", "travels", "winter", "snowfall", "brisk",
                      "cold", "beach", "seas"]
        mygame = Boggle(grid, dictionary)
        solution = mygame.get_solution()
        expected = ["HARBOR", "WINTER", "COLD", "BEACH"]
        self.assertEqual(sorted(expected), sorted(solution))


class TestSuiteSimpleEdgeCases(unittest.TestCase):
    """Tests simple and edge cases for the Boggle solver."""

    def test_square_grid_case_1x1(self):
        grid = [["A"]]
        dictionary = ["a", "b", "c"]
        mygame = Boggle(grid, dictionary)
        solution = mygame.get_solution()
        expected = []
        self.assertEqual(sorted(expected), sorted(solution))

    def test_empty_grid_case_0x0(self):
        grid = [[]]
        dictionary = ["hello", "there", "general", "kenobi"]
        mygame = Boggle(grid, dictionary)
        solution = mygame.get_solution()
        expected = []
        self.assertEqual(sorted(expected), sorted(solution))

    def test_empty_dictionary(self):
        grid = [["A", "B", "C"], ["D", "E", "F"], ["G", "H", "I"]]
        dictionary = []
        mygame = Boggle(grid, dictionary)
        solution = mygame.get_solution()
        expected = []
        self.assertEqual(sorted(expected), sorted(solution))


class TestSuiteCompleteCoverage(unittest.TestCase):
    """Comprehensive test suite for various Boggle cases."""

    def test_no_words_from_dictionary(self):
        grid = [["A", "B", "C"], ["D", "E", "F"], ["G", "H", "I"]]
        dictionary = ["xyz", "mno", "pqr"]
        mygame = Boggle(grid, dictionary)
        solution = mygame.get_solution()
        expected = []
        self.assertEqual(sorted(expected), sorted(solution))

    def test_partial_words_from_dictionary(self):
        grid = [["A", "B", "C"], ["D", "E", "F"], ["G", "H", "I"]]
        dictionary = ["abc", "cfi", "xyz", "ghi"]
        mygame = Boggle(grid, dictionary)
        solution = mygame.get_solution()
        expected = ["ABC", "CFI", "GHI"]
        self.assertEqual(sorted(expected), sorted(solution))

    def test_all_words_from_dictionary(self):
        grid = [["A", "B", "C"], ["D", "E", "F"], ["G", "H", "I"]]
        dictionary = ["abc", "cfi", "beh", "def", "ghi", "adg", "aei", "ceg"]
        mygame = Boggle(grid, dictionary)
        solution = mygame.get_solution()
        expected = ["ABC", "CFI", "BEH", "DEF", "GHI", "ADG", "AEI", "CEG"]
        self.assertEqual(sorted(expected), sorted(solution))


class TestSuiteQuAndSt(unittest.TestCase):
    """Tests Boggle grids containing 'Qu' and 'St' special cells."""

    def test_grid_with_multiple_multi_letter_cells_valid_words(self):
        grid = [["St", "A", "R"], ["Qu", "E", "T"], ["F", "G", "H"]]
        dictionary = ["star", "start", "quest", "quiet", "rat", "hat", "set"]
        mygame = Boggle(grid, dictionary)
        solution = mygame.get_solution()
        expected = ["STAR", "START", "QUEST", "RAT"]
        self.assertEqual(sorted(expected), sorted(solution))

    def test_grid_with_more_complex_words(self):
        grid = [["St", "A", "R"], ["Qu", "E", "T"], ["F", "G", "H"]]
        dictionary = ["stqufgearth", "startequfgh", "star", "start", "quest",
                      "quiet", "rat", "hat", "set"]
        mygame = Boggle(grid, dictionary)
        solution = mygame.get_solution()
        expected = ["STAR", "START", "QUEST", "RAT", "STARTEQUFGH",
                    "STQUFGEARTH"]
        self.assertEqual(sorted(expected), sorted(solution))


if __name__ == '__main__':
    unittest.main()
