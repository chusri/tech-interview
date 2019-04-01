#!/home/ubuntu/wspace-2/anaconda2/bin/python

import unittest
from Trie import TrieNode

class TestTrieNode(unittest.TestCase):
    def test_initialize_trie_node_object(self):
        node = TrieNode('a')
        self.assertEqual(node.character, 'a')
        self.assertEqual(node.value, None)
        self.assertEqual(node.children, [None]*26)
        self.assertFalse(node.is_end_of_word)

    def test_initialize_trie_node_object_with_alphabet_length(self):
        node = TrieNode('a', 4)
        self.assertEqual(node.character, 'a')
        self.assertEqual(node.value, None)
        self.assertEqual(node.children, [None]*4)
        self.assertFalse(node.is_end_of_word)

class TestTrie(unittest.TestCase):
    pass

if __name__ == '__main__':
    unittest.main()
