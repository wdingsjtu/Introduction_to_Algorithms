#!/usr/bin/env python


from __future__ import print_function
import random
from sorting import heap_sort as mysort


n = 10
rand_int_list = [random.randint(0, 20) for _ in range(n)]
print("A random list:")
print(rand_int_list, '\n')

print("StandarD results:")
print(sorted(rand_int_list), '\n')

mysort(rand_int_list)
print("Sorted by my implementation:")
print(rand_int_list, '\n')

is_identical = True if sorted(rand_int_list) == rand_int_list else False
print("My result is ", end='')
print(is_identical)
