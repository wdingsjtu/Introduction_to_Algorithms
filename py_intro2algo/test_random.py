#!/usr/bin/env python


from __future__ import print_function
import random
from sorting import heap_sort as mysort


def mysort_with_name_shown(*args, **kargs):
    print(mysort.__name__)
    return mysort(*args, **kargs)    

print("A random list:")
n = 10
rand_int_list = [random.randint(0, 20) for _ in range(n)]
print(rand_int_list, '\n')

print("Standard results:")
print(sorted(rand_int_list), '\n')

print("Sorted by my implementation:")
mysort_with_name_shown(rand_int_list)
print(rand_int_list, '\n')

is_identical = True if sorted(rand_int_list) == rand_int_list else False
print("My result is ", end='')
print(is_identical)
