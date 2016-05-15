/*--***************************************************************************

Chapter 7: Quick Sorting (p.95)
    quick_sort
    partition

***************************************************************************--*/

#ifndef SORTING_H
#define SORTING_H

void heap_sort(int* aList, int start, int end);
void   build_max_heap(int* aList, int lenOfList);
void   max_heapify(int* aList, int i, int end);
void quick_sort(int* aList, int start, int end);
int    partition(int* aList, int start, int end);

#endif
