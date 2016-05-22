from __future__ import print_function
from dataStructures import Queue

a = []
b = range(10)
qa = Queue(a)
qb = Queue(b)

print("An empty queue: ", qa)
print(type(qa))
print("Empty = ", qa.is_empty(), "Head = ",  qa.get_head())
qa.showq()

print("Push in: a")
qa.enqueue('a')
qa.showq()

pop = qa.dequeue()
print("Pop out: ", pop)
qa.showq()


print("An randon queue: ", qb)
print("Empty = ", qb.is_empty(), "Head = ", qb.get_head(), "Tail = ", qb.get_tail())
qb.showq()

print("Push in: a")
qb.enqueue('a')
qb.showq()

pop = qb.dequeue()
print("Pop out: ", pop)
qb.showq()

print("Push in:", pop)
qb.enqueue(pop)
qb.showq()
