/*--***************************************************************************

Chapter 7: Quick Sorting (p.95)
    quick_sort
    partition

***************************************************************************--*/

#include <algorithm>
#include "sorting.h"


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
