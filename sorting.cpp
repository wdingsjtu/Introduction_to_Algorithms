/*--***************************************************************************

Chapter 7: Quick Sorting (p.95)
    quick_sort
    partition

Chapter 8:
    ...

***************************************************************************--*/

#include <algorithm>
#include <iostream>
#include <stdlib.h>

void print_list(int* aList, int lenOfList);
void quick_sort(int* aList,  int start, int end);
int  partition(int* aList, int start, int end);
void swap(int* pa, int* pb);


int main(){

    const int len_list = 10;
    int aList[len_list];
    int aListSorted[len_list];

    std::cout << "A random list:" << "\n";
    for (int i=0; i<len_list; i++){
        aList[i] = rand() % 20 ;
    }
    print_list(aList, len_list);
    std::cout << "\n";

    std::cout << "Standard results:" << "\n";
    std::copy(aList, aList + len_list, aListSorted);
    std::sort(aListSorted, aListSorted + len_list);
    print_list(aListSorted, len_list);
    std::cout << "\n";

    std::cout << "Sorted by my implementation:" << "\n";    
    quick_sort(aList, 0, len_list - 1);
    print_list(aList, len_list);
    std::cout << "\n";    

    return 0;
}

void print_list(int* aList, int lenOfList){

    const int last = lenOfList - 1;

    std::cout << "[";
    for (int i=0; i<last; i++){
        std::cout << aList[i] << ", ";
    }
    std::cout << aList[last] << "]\n";
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
            swap(&aList[i], &aList[j]);
        }
    }
    i++;
    swap(&aList[i], &aList[end]);

    return i;
}

void swap(int* pa, int* pb){

    int temp;

    temp = *pa; *pa = *pb; *pb = temp;
}
