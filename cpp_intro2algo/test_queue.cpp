#include <iostream>
#include "dataStructures.h"

using namespace std;


int main(){

    int a[10];
    int pop;
    Queue qa;
    Queue qb(a, 8);

    for (int i=0; i<10; i++){
        a[i] = i;
    }

    cout << "An empty queue" << endl;
    cout << "Empty = " << boolalpha << qa.is_empty() << " ";
    cout << "Head = " << qa.get_head() << endl;
    qa.showq();
    qa.enqueue(1);
    qa.showq();
    qa.dequeue();
    qa.showq();

    cout << "An random queue:" << endl;
    cout << "Empty = " << boolalpha << qb.is_empty() << " ";
    cout << "Head = " << qb.get_head() << " ";
    cout << "Tail = " << qb.get_tail() << endl;
    qb.showq();
    cout << "Push in: 1" << endl;
    qb.enqueue(1);
    qb.showq();
    pop = qb.dequeue();
    cout << "Pop out: " << pop << endl;
    qb.showq();
    cout << "Push in: " << pop << endl;
    qb.enqueue(pop);
    qb.showq();

    return 0;
}
