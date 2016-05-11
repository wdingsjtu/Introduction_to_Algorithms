/*--***************************************************************************

    ...

***************************************************************************--*/

#include <algorithm>
#include <iostream>
#include "sorting.h"

void print_list(int* aList, int lenOfList);

int main(){

    const int len_list = 10;
    int rand_list[len_list];
    int std_sorted_list[len_list];
    bool is_identical = true;

    std::cout << "A random list:" << "\n";
    for (int i=0; i<len_list; i++){
       rand_list[i] = rand() % 20;
    }
    print_list(rand_list, len_list);
    std::cout << "\n";

    std::cout << "Standard results:" << "\n";
    std::copy(rand_list, rand_list + len_list, std_sorted_list);
    std::sort(std_sorted_list, std_sorted_list + len_list);
    print_list(std_sorted_list, len_list);
    std::cout << "\n";

    std::cout << "Sorted by my implementation:" << "\n";    
    quick_sort(rand_list, 0, len_list - 1);
    print_list(rand_list, len_list);
    std::cout << "\n";    

    std::cout << "My result is ";
    for (int i=0; i<len_list; i++){
        if (std_sorted_list[i] != rand_list[i]){
            is_identical = false;
            break;
        }
    }
    std::cout << std::boolalpha << is_identical << "\n";

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
