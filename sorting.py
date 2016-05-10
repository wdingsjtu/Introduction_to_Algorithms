'''
Chapter 7: Quick Sorting (p.95)
    quick_sort
    partition

Chapter 8:
    ...

'''
from __future__ import print_function


def partition(aList, start, end):
    '''
    ($7.1, p.95)

    type_aList: list
    type_start: int
    type_end: int
    rtype: int 
    '''
    pivot = aList[end]
    i = start - 1 
    for j in range(start, end): # start:end-1
        if aList[j] <= pivot:
            i += 1
            aList[i], aList[j] = aList[j], aList[i]
    i += 1
    aList[end], aList[i] = aList[i], aList[end]

    return i 

def quick_sort(aList, start=0, end=-1):
    '''
    Sort the whole 'aList' by default. 'end=-1' will be intepreted as 
    'len(aList)'. Return NONE since it's in-place. 

    ($7.1., p.95)

    type_aList: list
    type_start: int
    type_end: int
    rtype: None

    '''
    if end == -1:
        end = len(aList) - 1 
    if start < end:        
        mid = partition(aList, start, end)
        quick_sort(aList, start, mid-1)
        quick_sort(aList, mid+1, end)
