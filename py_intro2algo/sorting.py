'''
Chapter 6: Heap Sorting (p.85)
    heap_sort
      max_heapify
      build_max_heap
      
Chapter 7: Quick Sorting (p.95)
    quick_sort
      partition

Chapter 8:
    ...

'''
from __future__ import print_function


def max_heapify(aList, i):
    ''' i is the parent index in a least-unit tree.
    '''
    iLeft = 2*(i + 1) - 1
    iRight = 2*(i + 1)

    iMax = i 
    if iLeft < len(aList):
        iMax = iLeft if aList[iLeft] > aList[i] else iMax
    if iRight < len(aList):
        iMax = iRight if aList[iRight] > aList[iMax] else iMax
    elif iLeft > len(aList) - 1:
        pass
    
    if iMax != i:
        aList[i], aList[iMax] = aList[iMax], aList[i]
        max_heapify(aList, iMax)

def build_max_heap(aList):
    ''' For a heap (complete binary tree) with n (0 ~ n-1) elements, leaf 
    nodes start from (n+1)/2 - 1, i.e., (n-1)/2.
    
    '''
    iFirstLeaf = len(aList)//2
    for i in reversed(range(iFirstLeaf + 1)):
        max_heapify(aList, i)

def heap_sort(aList):
    '''
    Recursively build a max heap (hence 1st element is the maximum), and max-
    heapify the rest.
    
    '''
    build_max_heap(aList)
    for i in reversed(range(1, len(aList))):
        aList[0], aList[i] = aList[i], aList[0]
        
        b = aList[:i]
        max_heapify(b, 0)
        aList[:i] = b
        #TODO: in-place??


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
