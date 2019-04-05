#!/home/ubuntu/wspace-2/anaconda2/bin/python

import string
import unittest
from Trie import TrieNode
from Trie import Trie

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

    def test_search_key_in_empty_trie(self):
        trie = Trie()
        self.assertIsNone(trie.search_key('hello'))

    def test_insert_key_with_unique_characters_in_empty_trie(self):
        trie = Trie()
        trie.insert_key(string.ascii_lowercase, 1)
        self.assertEqual(trie.search_key(string.ascii_lowercase), 1)

    def test_insert_key_with_duplicate_characters_in_empty_trie(self):
        trie = Trie()
        trie.insert_key('helloo', 1)
        self.assertEqual(trie.search_key('helloo'), 1)

if __name__ == '__main__':
    unittest.main()
