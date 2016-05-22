/*--***************************************************************************

Chapter 6: Heap Sorting (p.84)
    heap_sort               (p.89)  
      max_heapify --------- (p.86)
      build_max_heap ------ (p.87)

Chapter 7: Quick Sorting (p.95)
    quick_sort              (p.)
      partition ----------- (p.)

***************************************************************************--*/

#ifndef SORTING_H
#define SORTING_H

void heap_sort(int* aList, int start, int end);
void   build_max_heap(int* aList, int lenOfList);
void   max_heapify(int* aList, int i, int end);
void quick_sort(int* aList, int start, int end);
int    partition(int* aList, int start, int end);

#endif
