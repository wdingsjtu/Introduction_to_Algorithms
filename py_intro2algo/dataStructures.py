'''
Basic Structures:
    Queue                   (p.130)

Chapter 6:
    Priority Queue          (p.161)


'''
from __future__ import print_function


class Queue(list):
    def __init__(self, aList):
        list.__init__(self, aList)
        self._size = len(aList)
        self._head = 0
        self._tail = self._size - 1

    def is_empty(self):
        if self._size == 0:
            return True
        elif self._tail + 1 == self._head:
            return True
        else:
            return False

    def get_head(self):
        if self.is_empty():
            return None
        else:
            return self._head

    def get_tail(self):
        if self.is_empty():
            return None
        else:
            return self._tail

    def showq(self):
        if self.is_empty():
            print()
        else:
            h = self._head % self._size
            t = (self._tail + 1) % self._size
            if h < t:
                for x in self[h:t]:
                    print(x, end=" ")
                print()
            else:
                for x in self[h: ]:
                    print(x, end=" ")
                for x in self[ :t]:
                    print(x, end=" ")
                print()

    def enqueue(self, x):
        if self._tail + 1 - self._head == self._size:
            print("Enqueue failed. Queue is full.")
        else:
            if (self._tail + 1 - self._head) % self._size:
                self._tail += 1
                self[self._tail % self._size] = x
            else:
                print("Enqueue dailed. Queue is full.")

    def dequeue(self):
        if self.is_empty():
            print("Dequeue failed. Queue is empty.")
        else:
            self._head += 1
            return self[self._head - 1]
