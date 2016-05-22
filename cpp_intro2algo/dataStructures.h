#ifndef DATASTRUCTURES_H_
#define DATASTRUCTURES_H_

class Queue
{
private:
    int  _size;
    int  _head;
    int  _tail;
    int* _origin;

public:
    Queue();
    Queue(int* list, const int size);
    bool  is_empty();
    int   get_head();
    int   get_tail();
    void  showq();
    void  enqueue(int x);
    int   dequeue();
};


#endif
