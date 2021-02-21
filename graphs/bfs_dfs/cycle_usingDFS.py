def canFinish(numCourses, prerequisites):  
#create a dictionary with #numCourses no. of keys.
    dicn={new_list:[] for new_list in range(numCourses)}
    
    #link the prerequisites[i][0] to its corresponding key in the dictionary
    #like for [[1,0],[0,1],[0,2], [1,2]], d={ 1: [0]
    #                             0: [1] 
    #                             2: [0,1]
    # }
    for val,key in enumerate(prerequisites):
            dicn.setdefault(prerequisites[val][1], []).append(prerequisites[val][0])
            
    #an empty list to keep track of visited nodes
    visited=[]
    
    # fucntion to visit every vertex with visited[] and stack() keeping track of back edges
    def dfs(dicn, visited):
        stack=set()
        for v in [*dicn]:
            if v not in visited:
                if dfs_visit(dicn, v, visited, stack)==False:
                    return False
        return True
    
    # recursive fucntion to check for back edges
    def dfs_visit(dicn, v, visited, stack):
        if v in stack:
            return False
        stack.add(v)
        for vs in dicn[v]:
            if vs not in visited:
                if dfs_visit(dicn, vs, visited, stack)==False:
                    return False
        stack.remove(v)
        visited.append(v)
        return True
    return dfs(dicn, visited)

print(canFinish(3,[[1,0],[0,1],[2,1]]))
print(canFinish(2,[[1,0],[0,1]]))
print(canFinish(3,[[1,0],[0,2]]))
print(canFinish(2,[[1,0]]))
    
    