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
        self.alphabet_length = alphabet_length
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

    def insert_key(self, key, value):
        """
        Insert key into Trie.

        Arguments:
        self
        key -- string to be inserted into trie
        value -- value associated with key

        Returns:
        None
        """

        current_node = self.root

        for character in key:
            child = self._search_character_in_node_children(current_node,
                                                            character)
            if child != None:
                current_node = child
            else:
                index = self._get_first_empty_child_index(current_node)
                current_node.children[index] = TrieNode(character,
                                                        self.root.alphabet_length)
        current_node.value = value
        current_node.is_end_of_word = True

    def search_key(self, key):
        """
        Search for key in Trie.

        Arguments:
        self
        key -- string to be searched

        Returns:
        value -- value associated with key or None if key not found
        """

        current_node = self.root

        for character in key:
            child = self._search_character_in_node_children(current_node,
                                                            character)
            if child != None:
                current_node = child
            else:
                return None

        if current_node.is_end_of_word:
            return current_node.value
        else:
            return None

    def _search_character_in_node_children(self, node, character):
        """
        Search for character in node's children.

        Arguments:
        self
        node -- node in trie
        character -- character to be searched

        Returns:
        node associated with character or None if character not found
        """

        for child in node.children:
            if child != None and character == child.character:
                return child

        return None

    def _get_first_empty_child_index(self, node):
        """
        Search for first empty slot in node's children.

        Arguments:
        self
        node -- node in trie

        Returns:
        Index of first empty slot in node's children or None if full
        """

        index = 0

        for child in node.children:
            if child == None:
                return index
            else:
                index += 1

        return None
