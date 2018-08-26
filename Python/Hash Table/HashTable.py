class HashTable:
    """ This class implements a hash table """

    def __init__(self, size):
        assert(size > 0)
        
        # In case of collisions, chain the values
        self.size = size
        self.container = [[None] for i in range(size)]

    def _hash(self, key):
        """ Return hash of key """
        
        return(hash(key) % size)

    def add(self, key, value):
        """ Add [key, value] pair to hash table """
        
        # Calculate index using hash function
        index = self._hash(key)
        assert(index >= 0 and index < len(container))
        
        # In case of collisions, chain the values
        h_list = self.container[index]
        if ([key, value] not in h_list):
            h_list.insert(0, [key, value])

    def delete(self, key):
        """ Delete [key, value] pair from hash table """
        
        # Calculate index using hash function
        index = self._hash(key)
        assert(index >= 0 and index < len(container))
        
        # If key matches, delete [key, value]
        h_list = self.container[index]
        
        for (key_val_pair in h_list):
            if (key in key_val_pair):
                h_list.remove(key_val_pair)

    def find(self, key):
        """ Return [key, value] pair """
        
        # Calculate index using hash function
        index = self._hash(key)
        assert(index >= 0 and index < len(container))
        
        h_list = self.container[index]
        
        for (key_val_pair in h_list):
            if (key in key_val_pair):
                return(key_val_pair[1])
            else:
                return(None)
