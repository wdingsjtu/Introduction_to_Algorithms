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
        self.left = None
        self.right = None
        self.tree = None

    def __repr__(self):
        return str(self.value)
  
    def _find_parent(self):
        parent_index = (self.tree.index(self) + 1)//2 - 1
        if parent_index >= 0:
            return parent_index

    def get_parent(self):
        if self._find_parent() is not None:
            return self.tree[self._find_parent()]

    def set_parent(self, node):
        if not isinstance(node, type(self)):
            raise TypeError("%s cannot be set as a node." %node)
        if self._find_parent() is not None:
            self.tree[self._find_parent()] = node

    parent = property(get_parent, set_parent)
  

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
       
#    def left(self, node):
#        left_index = (self.index(node) + 1)*2 - 1
#        if left_index > len(self) - 1:
#            return None
#        else:
#            return self[left_index]
#
#    def right(self, node):
#        right_index = (self.index(node) + 1)*2
#        if right_index > len(self) - 1:
#            return None
#        else:
#            return self[right_index]
