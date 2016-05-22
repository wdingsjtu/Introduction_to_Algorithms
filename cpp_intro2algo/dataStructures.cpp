/*--***************************************************************************

Chapter 10: Basic Structures (p.129)
    Queue                   (p.130) 

Chapter 6:
    Priority Queue          (p.90)

***************************************************************************--*/


#include <iostream>
#include "dataStructures.h"
#include "sorting.h"


Queue::Queue(){
    _size = 0;
    _origin = NULL;
    _head = -1;
    _tail = -1;
}

Queue::Queue(int* aList, const int size){
    if (size == 0){
        _size = 0;
    }else{
        _size = size;
        _origin = aList;
        _head = 0;
        _tail = size - 1;
    }
}

bool Queue::is_empty(){
    if (_size == 0){
        return true;
    }else if (_head == _tail){
        return true;
    }else{
        return false;
    }
}

int Queue::get_head(){
    if (not is_empty()){
        return _head;
        //return *(_origin + _head);
    }else{
        return -1;
    }

}

int Queue::get_tail(){
    if (not is_empty()){
        return _tail;
        //return *(_origin + _tail);
    }else{
        return -1;
    }
}

void Queue::showq(){
    if (is_empty()){
        //pass
    }else if (_head <= _tail){
        for (int i=_head; i<=_tail; i++){
            std::cout << *(_origin + i) << " ";
        }
    }else{
        for (int i=_head; i<_size; i++){
            std::cout << *(_origin + i) << " ";
        }
        for (int i=0; i<=_tail; i++){
            std::cout << *(_origin + i) << " ";
        }
    }
    std::cout << std::endl;
}

void Queue::enqueue(int x){
    if (_size == 0){
        std::cout << "Enqueue failed. Queue is full." << std::endl;
    }else if ((_tail + 1 - _head) % _size){
        _tail = (_tail + 1) % _size;
        *(_origin + _tail) = x;
    }else{
        std::cout << "Enqueue failed. Queue " << "is full." << std::endl;
    }
}

int Queue::dequeue(){
    if (is_empty()){
        std::cout << "Dequeue failed. Queue " << "is empty." << std::endl;
    }else{
       _head = (_head + 1) % _size;
       return *(_origin + _head - 1);
    }
}
