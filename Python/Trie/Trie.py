""" Implement the Trie data structure. """

class TrieNode():
    def __init__(self, character, alphabet_length=26):
        """
        Initialize TrieNode object.

        Arguments:
        self
        character -- character to insert into Trie
        alphabet_length -- number of characters in the alphabet

        Returns:
        None
        """

        self.character = character
        self.value = None
        self.children = [None]*alphabet_length
        self.is_end_of_word = False

class Trie():
    def __init__(self):
        """
        Initialize Trie object.

        Arguments:
        self

        Returns:
        None
        """

        self.root = TrieNode(None)

