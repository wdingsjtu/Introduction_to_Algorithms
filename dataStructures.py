'''
Basic Structures:
    BinaryTree (p.690)

Chapter 12: Binary Search Tree (p.161)
    ... 

'''
from __future__ import print_function


class BinaryTreeNode(object):
    def __init__(self, value):
        self.value = value
        self._parent = None
        self._left = None
        self._right = None
        self.tree = None

    def __repr__(self):
        return str(self.value)
  
    def _getter(self, index):
        if 0 <= index < len(self.tree):
            return self.tree[index]

    def _setter(self, index, node):
        if not isinstance(node, type(self)):
            raise TypeError("%s cannot be set as a node." %node)
        if 0 <= index < len(self.tree):
            self.tree[index] = node

    def _find_parent(self):
        ''' Return the index of parent node.
        '''
        return (self.tree.index(self) + 1)//2 - 1

    def _find_left(self):
        return (self.index(node) + 1)*2 - 1

    def _find_right(self):
        right_index = (self.index(node) + 1)*2

    def get_parent(self):
        return self._getter(self._find_parent())

    def set_parent(self, node):
        return self._setter(self._find_parent(), node)

    def get_left(self):
        return self._getter(self._find_left())

    def get_right(self):
        return self._getter(self._find_right())

    def set_left(self, node):
        return self._setter(self._find_left(), node)

    def set_right(self, node):
        return self._setter(self._find_right(), node)

    parent = property(get_parent, set_parent)
    left = property(get_left, set_left)
    right = property(get_right, set_right)

class BinaryTree(list):
    ''' A complete binary tree implemented by list (sequence storage).
    '''
    def __init__(self, iterable):
        list.__init__(self, map(BinaryTreeNode, iterable))

        try:
            self.root = self[0] 
        except IndexError:
            self.root = None

        for nodes in self:
            nodes.tree = self
