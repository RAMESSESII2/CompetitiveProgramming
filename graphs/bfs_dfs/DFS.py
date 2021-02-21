""" class Node:
    def __init__(self, name):
        self.children=[]
        self.name=name
    
    def addChild(self, name):
        self.children.append(Node(name))

#O(V+E) time| O(V) space
    def dfs(self, array):
        array.append(self.name)
        for child in self.children:
            child.dfs(array)
        return array

Tree= Node(3)
Tree.addChild(4)
Tree.addChild(5)
 """

""" graph1= {
'A' : ['B','S'],
'B' : ['A'],
'C' : ['D','E','F','S'],
'D' : ['C'],
'E' : ['C','H'],
'F' : ['C','G'],
'G' : ['F','S'],
'H' : ['E','G'],
'S' : ['A','C','G']
}
 """
graph1= {
'A' : ['B','S'],
'B' : [],
'C' : ['E','S'],
'D' : ['C'],
'E' : ['H'],
'F' : ['C'],
'G' : ['F','S'],
'H' : ['G'],
'S' : []
}
visited = []
def dfs_visit(graph, s):
    global visited
    for v in graph[s]:
        if v not in visited:
            visited.append(v)
            dfs_visit(graph, v)
def dfs(graph):
    global visited
    for v in [*graph]:
        if v not in visited:
            visited.append(v)
            dfs_visit(graph,v)
#O(V+E)
dfs(graph1)
print(visited)