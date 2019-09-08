#!/home/ubuntu/wspace-2/anaconda2/bin/python

import unittest
from Cache import Cache
from CacheLine import CacheLine

class TestCache(unittest.TestCase):
    def test_raise_exception_if_num_blocks_not_power_2(self):
        with self.assertRaises(ValueError):
            _ = Cache(63)

    def test_raise_exception_if_block_size_not_power_2(self):
        with self.assertRaises(ValueError):
            _ = Cache(64, 63)

    def test_raise_exception_if_associativity_not_power_2(self):
        with self.assertRaises(ValueError):
            _ = Cache(64, 64, -1)

    def test_0_is_not_power_of_2(self):
        cache = Cache()
        self.assertEqual(cache._is_power_2(0), False)

    def test_Minus_1_is_not_power_of_2(self):
        cache = Cache()
        self.assertEqual(cache._is_power_2(-1), False)

    def test_32_is_power_of_2(self):
        cache = Cache()
        self.assertEqual(cache._is_power_2(32), True)

    def test_31_is_not_power_of_2(self):
        cache = Cache()
        self.assertEqual(cache._is_power_2(31), False)

    def test_direct_mapped_cache(self):
        cache = Cache(64, 64, 1)
        self.assertEqual(cache.size, 64*64)
        self.assertEqual(cache.sets, 64)
        self.assertEqual(len(cache.container), 64)
        self.assertEqual(len(cache.container[0]), 1)

    def test_fully_associative_cache(self):
        cache = Cache(64, 64, 64)
        self.assertEqual(cache.size, 64*64)
        self.assertEqual(cache.sets, 1)
        self.assertEqual(len(cache.container), 1)
        self.assertEqual(len(cache.container[0]), 64)

    def test_4_way_associative_cache(self):
        cache = Cache(64, 64, 4)
        self.assertEqual(cache.size, 64*64)
        self.assertEqual(cache.sets, 16)
        self.assertEqual(len(cache.container), 16)
        self.assertEqual(len(cache.container[0]), 4)

class TestCacheLine(unittest.TestCase):
    def test_init(self):
        cacheline = CacheLine()
        self.assertEqual(cacheline.valid, False)
        self.assertEqual(cacheline.dirty, False)
        self.assertEqual(cacheline.tag, None)

if __name__ == '__main__':
    unittest.main()
