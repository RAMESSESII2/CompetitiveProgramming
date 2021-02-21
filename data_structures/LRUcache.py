# from collections import OrderedDict
# class LRUCache(OrderedDict):

#     def __init__(self, capacity):
#         """
#         :type capacity: int
#         """
#         self.capacity = capacity

#     def get(self, key):
#         """
#         :type key: int
#         :rtype: int
#         """
#         if key not in self:
#             return - 1
        
#         self.move_to_end(key)
#         return self[key]

#     def put(self, key, value):
#         """
#         :type key: int
#         :type value: int
#         :rtype: void
#         """
#         if key in self:
#             self.move_to_end(key)
#         self[key] = value
#         if len(self) > self.capacity:
#             self.popitem(last = False)


class DoublyLinkedListNodes:
    def __init__(self, key, value):
        self.key= key
        self.value= value
        self.next= None
        self.prev= None
    def removeBindings(self):
        if self.prev is not None:
            self.prev.next=self.next
        if self.next is not None:
            self.next.prev=self.prev
        self.next=None
        self.prev=None

class DoublyLinkedList:
    def __init__(self):
        self.head= None
        self.tail= None

    def setHeadTo(self, node):
        if self.head==None:
            self.head=node
            self.tail=node
        elif self.head==self.tail:
            self.tail.prev=node
            self.head=node
            self.head.next=self.tail
        elif self.head==node:
            return
        else:
            if self.tail==node:
                self.removeTail()
            node.removeBindings()
            self.head.prev=node
            node.next=self.head
            self.head=node
    
    def removeTail(self):
        if self.tail is None:
            return
        if self.tail==self.head:
            self.head=None
            self.tail=None
            return
        self.tail= self.tail.prev
        self.tail.next=None

class LRUCache:
    def __init__(self, maxSize):
        self.cache={}
        self.maxSize= maxSize or 1
        self.currentSize=0
        self.listofMostRecent= DoublyLinkedList()

    def insertKeyValuePairs(self, key, value):
        if key not in self.cache:
            if self.currentSize==self.maxSize:
                self.evictLeastRecent()
            else:
                self.currentSize+=1
            self.cache[key]= DoublyLinkedListNodes(key, value)
        else:
            self.replaceKey(key,value)
        self.updateMostRecent(self.cache[key])

    def updateMostRecent(self, node):
        self.listofMostRecent.setHeadTo(node)
    
    def evictLeastRecent(self):
        keyToRemove = self.listofMostRecent.tail.key
        self.listofMostRecent.removeTail()
        del self.cache[keyToRemove]
    
    def replaceKey(self, key, value):
        if key not in self.cache:
            raise Exception("The provided key is not in the cache")
        self.cache[key].value= value

    def getValueFromKey(self, key):
        if key not in self.cache:
            return None
        self.updateMostRecent(self.cache[key])
        return self.cache[key].value
    
    def getMostRecentKey(self):
        return self.listofMostRecent.head.key
    

    
