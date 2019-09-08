#!/home/ubuntu/wspace-2/anaconda2/bin/python

import unittest
from Cache import Cache

class TestCache(unittest.TestCase):
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

if __name__ == '__main__':
    unittest.main()
