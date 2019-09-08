""" Implement the Cache class. """

class Cache(object):
    def __init__(self, num_blocks=64, block_size=64, associativity=1):
        """
        Initialize Cache object.

        Arguments:
        self
        num_blocks -- number of blocks in cache
        block_size -- cache block size in bytes
        associativity -- set associativity (1=direct mapped, num_blocks=fully
        associative)

        Returns:
        None
        """

        self._check_init_args(num_blocks, block_size, associativity)

        self.num_blocks = num_blocks
        self.size = num_blocks * block_size
        self.associativity = associativity
        self.sets = num_blocks/associativity
        self.container = [[None]*associativity for _ in range(self.sets)]

    def _check_init_args(self, num_blocks, block_size, associativity):
        """
        Check for validity of __init__() arguments.

        Arguments:
        self
        num_blocks -- number of blocks in cache
        block_size -- cache block size in bytes
        associativity -- set associativity (1=direct mapped, num_blocks=fully
        associative)

        Returns:
        None
        """

        if not self._is_power_2(num_blocks):
            raise ValueError('num_blocks not power of 2')

        if not self._is_power_2(block_size):
            raise ValueError('block_size not power of 2')

        if not self._is_power_2(associativity):
            raise ValueError('associativity not power of 2')

    def _is_power_2(self, number):
        """
        Is number a power of 2.

        Arguments:
        self
        number -- number

        Returns:
        True or False
        """

        return number > 0 and ((number & (number-1)) == 0)

