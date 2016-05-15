/*--***************************************************************************
Chapter 6: Heap Sorting
    heap_sort
      max_heapify
      build_max_heap

Chapter 7: Quick Sorting (p.95)
    quick_sort
      partition

//TODO int -> template

***************************************************************************--*/

#include <algorithm>
#include "sorting.h"


void max_heapify(int* aList, int i, int end){

    int iLeft = 2 * i + 1;    //(i + 1)*2 - 1
    int iRight = 2 * (i + 1); //(i + 1)*2 - 1 + 1
    int iMax = i;

    if (iLeft <= end){
        if (aList[iLeft] > aList[iMax]){
            iMax = iLeft;
        }
    }
    if (iRight <= end){
        if (aList[iRight] > aList[iMax]){           
            iMax = iRight;
        }
    }else if (iLeft > end){
    }

    if (iMax != i){
        std::swap(aList[iMax], aList[i]);
        max_heapify(aList, iMax, end);
    }
}

void build_max_heap(int* aList, int lenOfList){

    int iLastNonleaf = (lenOfList - 1)/2; //(lenOfList + 1)/2 - 1;

    for (int i=iLastNonleaf; i>=0; i--){
        max_heapify(aList, i, lenOfList - 1);
    }
}

void heap_sort(int* aList, int start, int end){

    int lenOfList = end - start + 1;

    build_max_heap(&aList[start], lenOfList);
    for (int i=end; i>start; i--){
        std::swap(aList[i], aList[start]);
        max_heapify(&aList[start], start, i-1);
    }
}


void quick_sort(int* aList,  int start, int end){

  int mid;

  if (start < end){
    mid = partition(aList, start, end);
    quick_sort(aList, start, mid-1);
    quick_sort(aList, mid+1, end);
  }
}

int partition(int* aList, int start, int end){

  int pivot = aList[end];
  int i = start - 1;
  int j; 

  for (j=start; j<end; j++){
    if (aList[j] < pivot){
      i++;
      std::swap(aList[i], aList[j]);
    }
  }
  i++;
  std::swap(aList[i], aList[end]);

  return i;
}
