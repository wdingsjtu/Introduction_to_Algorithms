#from dataStructures import BinaryTreeNode as Node
from dataStructures import BinaryTree as BT

a = [16, 14, 10, 8, 7, 9, 3, 2, 4, 1]

a = BT(a)

print(a)
print(type(a))
print(a[0])
print(type(a[0]))
print("\n")

print(a[1].parent)
print(id(a[1].parent))
print(id(a[0]))
a[1].parent, a[1] = a[1], a[1].parent

print("\nafter setter:")
print(a[1].parent)
print(a[0])
print(type(a[0]))
print(a)
print(dir(a))
print(dir(a[1]))
