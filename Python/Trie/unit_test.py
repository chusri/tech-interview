#!/home/ubuntu/wspace-2/anaconda2/bin/python

import string
import unittest
from Trie import TrieNode
from Trie import Trie
from SuffixTrie import SuffixTrie
from PatternMatching import *

class TestTrieNode(unittest.TestCase):
    def test_initialize_trie_node_object(self):
        node = TrieNode('a')
        self.assertEqual(node.character, 'a')
        self.assertIsNone(node.value)
        self.assertEqual(node.alphabet_length, 26)
        self.assertEqual(node.children, [None]*26)
        self.assertFalse(node.is_end_of_word)

    def test_initialize_trie_node_object_with_alphabet_length(self):
        node = TrieNode('a', 4)
        self.assertEqual(node.character, 'a')
        self.assertIsNone(node.value)
        self.assertEqual(node.alphabet_length, 4)
        self.assertEqual(node.children, [None]*4)
        self.assertFalse(node.is_end_of_word)

class TestTrie(unittest.TestCase):
    def test_initialize_trie_object(self):
        trie = Trie()
        self.assertIsNone(trie.root.character)
        self.assertIsNone(trie.root.value)
        self.assertEqual(trie.root.children, [None]*26)
        self.assertFalse(trie.root.is_end_of_word)

    def test_initialize_trie_object_with_alphabet_length(self):
        trie = Trie(4)
        self.assertIsNone(trie.root.character)
        self.assertIsNone(trie.root.value)
        self.assertEqual(trie.root.children, [None]*4)
        self.assertFalse(trie.root.is_end_of_word)

    def test_insert_key_with_unique_characters_in_empty_trie(self):
        trie = Trie()
        trie.insert_key(string.ascii_lowercase, 1)
        self.assertEqual(trie.search_key(string.ascii_lowercase), 1)

    def test_insert_key_with_duplicate_characters_in_empty_trie(self):
        trie = Trie()
        trie.insert_key('helloo', 1)
        self.assertEqual(trie.search_key('helloo'), 1)

    def test_insert_multiple_keys_in_trie(self):
        trie = Trie()
        trie.insert_key('their', 1)
        trie.insert_key('there', 2)
        trie.insert_key('answer', 3)
        trie.insert_key('any', 4)
        trie.insert_key('bye', 5)

        self.assertEqual(trie.search_key('their'), 1)
        self.assertEqual(trie.search_key('there'), 2)
        self.assertEqual(trie.search_key('answer'), 3)
        self.assertEqual(trie.search_key('any'), 4)
        self.assertEqual(trie.search_key('bye'), 5)

    def test_search_key_in_empty_trie(self):
        trie = Trie()
        self.assertIsNone(trie.search_key('hello'))

    def test_search_key_not_in_trie(self):
        trie = Trie()
        trie.insert_key('their', 1)
        trie.insert_key('there', 2)
        trie.insert_key('answer', 3)
        trie.insert_key('any', 4)
        trie.insert_key('bye', 5)

        self.assertIsNone(trie.search_key('hello'))

class TestSuffixTrie(unittest.TestCase):
    def test_is_prefix_of_suffix_in_empty_suffix_trie(self):
        suffix_trie = SuffixTrie()
        self.assertFalse(suffix_trie.is_prefix_of_suffix('hello'))

    def test_search_for_prefix_in_suffix_trie(self):
        suffix_trie = SuffixTrie()
        suffix_trie.insert_key('baaba', 1)
        suffix_trie.insert_key('aaba', 2)
        suffix_trie.insert_key('aba', 3)
        suffix_trie.insert_key('ba', 4)
        suffix_trie.insert_key('a', 5)

        self.assertTrue(suffix_trie.is_prefix_of_suffix('baa'))

class TestPatternMatching(unittest.TestCase):
    def test_random_genome_sequence_generator(self):
        random.seed(10)
        sequence = generate_single_random_genome_sequence(10)
        self.assertEqual('GCGATTGAGC', sequence)

    def test_multiple_random_genome_sequence_generator(self):
        random.seed(10)
        sequences = generate_random_genome_sequences(10, 5)
        self.assertEqual(['CGATTGA', 'CATTAT', 'CCGCGGA', 'TTGAAATCC',
                          'CGCAGTAACA'], sequences)

    def test_generate_text_prefixes(self):
        prefixes = generate_text_prefixes('apple')
        self.assertEqual(['a', 'ap', 'app', 'appl', 'apple'], prefixes)

    def test_generate_text_suffixes(self):
        suffixes = generate_text_suffixes('apple')
        self.assertEqual(['apple', 'pple', 'ple', 'le', 'e'], suffixes)

    def test_prefix_trie_matching(self):
        trie = Trie(4)
        text = 'CGCAGTAACA'
        patterns = ['CGCA', 'CGCAGT', 'CGC', 'C']

        for pattern in patterns:
            trie.insert_key(pattern, len(pattern))

        prefix_matches = prefix_trie_matching(text, trie)
        self.assertEqual(['C', 'CGC', 'CGCA', 'CGCAGT'], prefix_matches)

    def test_prefix_trie_matching_pattern_not_found(self):
        trie = Trie(4)
        text = 'CGCAGTAACA'
        patterns = ['ATC', 'CAT', 'CGTA']

        for pattern in patterns:
            trie.insert_key(pattern, len(pattern))

        prefix_matches = prefix_trie_matching(text, trie)
        self.assertEqual([], prefix_matches)

    def test_trie_matching(self):
        trie = Trie(4)
        text = 'CGCAGTAACA'
        patterns = ['CGCA', 'CA', 'CAGTA', 'AGTA']

        for pattern in patterns:
            trie.insert_key(pattern, len(pattern))

        matches = trie_matching(text, trie)
        expected_matches = [['CGCA'], [], ['CA', 'CAGTA'], ['AGTA'], [], [], [], [], ['CA'], []]
        self.assertEqual(expected_matches, matches)

    def test_trie_matching_pattern_not_found(self):
        trie = Trie(4)
        text = 'CGCAGTAACA'
        patterns = ['ATC', 'CAT', 'CGTA']

        for pattern in patterns:
            trie.insert_key(pattern, len(pattern))

        matches = trie_matching(text, trie)
        expected_matches = [[], [], [], [], [], [], [], [], [], []]
        self.assertEqual(expected_matches, matches)

if __name__ == '__main__':
    unittest.main()
