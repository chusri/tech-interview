""" Implement the CacheLine class. """

class CacheLine(object):
    def __init__(self, valid=False, dirty=False, tag=None):
        """
        Initialize CacheLine object.

        Arguments:
        self
        valid -- Is the cache line valid?
        dirty -- Is the cache line dirty?
        tag -- Cache tag

        Returns:
        None
        """

        self.valid = valid
        self.dirty = dirty
        self.tag = tag
