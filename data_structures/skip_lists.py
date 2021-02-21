import random
import sys

sys.stdout = open("out.txt", "w")
sys.stdin = open("in.txt", "r")
# import os import math
# import numpy as np
# from collections import OrderedDict
# from memo import memo #@memo
# from functools import lru_cache #@lru_cache
# from collections import deque #list = deque()
# from queue import *


class node:
    # Initialise the node
    def __init__(self, key, level):
        # value of node
        self.key = key
        # a forward list to hold references to another levels
        self.forward = [None] * (level + 1)


class skipList:
    def __init__(self, maxml, p):
        # maxm level for this skip list
        self.max_level = maxml

        # p denotes no. of nodes having i references which also have i+1 references
        self.p = p

        # create header node and initialise it to -1
        self.header = self.createNode(self.max_level, -1)

        # current level of skip list
        self.level = 0

    # create new node
    def createNode(self, lvl, key):
        n = node(key, lvl)
        return n

    # create random level for node
    def randomLevel(self):
        lvl = 0
        while random.random() < self.p and lvl < self.max_level:
            lvl += 1
        return lvl

    # inset keys into the skip list
    def insertKey(self, key):
        # create update array and initialise it
        update = [None] * (self.max_level + 1)
        current = self.header

        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].key < key:
                current = current.forward[i]
            update[i] = current
        # reached level 0 and forward reference to  right, which is desired position to  insert key.
        current = current.forward[0]

        if current == None or current.key != key:
            # Generate a random level for node
            rlevel = self.randomLevel()
            """ 
            If random level is greater than list's current 
            level (node with highest level inserted in  
            list so far), initialize update value with reference 
            to header for further use 
            """
            if rlevel > self.level:
                for i in range(self.level + 1, rlevel + 1):
                    update[i] = self.header
                self.level = rlevel

            # create new node with random level generated
            n = self.createNode(rlevel, key)

            # insert node by rearranging references
            for i in range(rlevel + 1):
                n.forward[i] = update[i].forward[i]
                update[i].forward[i] = n

            print("Successfully inserted key {}".format(key))

    # Search for a key in a skip list
    def searchList(self, key):
        current = self.header
        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].key < key:
                current = current.forward[i]
        current = current.forward[0]

        if current and current.key == key:
            return 1
        return 0

    # remove a key from skip list
    def removeKey(self, key):
        update = [None] * (self.max_level + 1)
        current = self.header
        for i in range(self.level, -1, -1):
            while current.forward[i] and current.forward[i].key < key:
                current = current.forward[i]
            update[i] = current
        current = current.forward[0]
        if current != None and current.key == key:
            """
            start from lowest level and rearrange references
            just like we do in singly linked list
            to remove target node
            """
            for i in range(self.level + 1):
                """
                If at level i, next node is not target
                node, break the loop, no need to move
                further level
                """
                if update[i].forward[i] != current:
                    break
                update[i].forward[i] = current.forward[i]

            # Remove levels having no elements
            while self.level > 0 and self.header.forward[self.level] == None:
                self.level -= 1
            print("Successfully deleted {}".format(key))

    def displayList(self):
        print("\n*****Skip List******")
        head = self.header
        for lvl in range(self.level + 1):
            print("Level {}: ".format(lvl), end=" ")
            node = head.forward[lvl]
            while node != None:
                print(node.key, end=" ")
                node = node.forward[lvl]
            print("")


if __name__ == "__main__":
    # for i in range(int(input())):
    # N = int(input())
    # pc pr = map(int input().split())
    arr = list(map(int, input().split()))
    key = int(input())
    rkey = int(input())
    skpl = skipList(len(arr) // 2, 0.5)
    for i in range(len(arr)):
        skpl.insertKey(arr[i])
    skpl.displayList()
    r = skpl.searchList(key)
    if r == 1:
        print("FOUND")
    else:
        print("NOT FOUND")

    skpl.removeKey(rkey)
    skpl.displayList()

# input :
# 3344 -234 6 7 34 4 56 -3 0 45
# 56
# 3344

# output:
# Successfully inserted key 3344
# Successfully inserted key -234
# Successfully inserted key 6
# Successfully inserted key 7
# Successfully inserted key 34
# Successfully inserted key 4
# Successfully inserted key 56
# Successfully inserted key -3
# Successfully inserted key 0
# Successfully inserted key 45

# *****Skip List******
# Level 0:  -234 -3 0 4 6 7 34 45 56 3344 
# Level 1:  -234 0 7 56 
# Level 2:  7 56 
# FOUND
# Successfully deleted 3344

# *****Skip List******
# Level 0:  -234 -3 0 4 6 7 34 45 56 
# Level 1:  -234 0 7 56 
# Level 2:  7 56 
:
