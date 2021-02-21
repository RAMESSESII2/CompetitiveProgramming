import time
start_time = time.time()

def maze(grid, i, j):
    if not grid:
        return False
    if grid[len(grid)-1][len(grid[0])-1]==1:
        return False
    if i==len(grid)-1 and j==len(grid[0])-1:
        return True
    for r in [i-1, i+1]:
        if helper(grid, r, j):
            grid[i][j]=1
            if maze(grid, r, j):
                return True
            grid[i][j]=0
    for c in [j-1, j+1]:
        if helper(grid, i, c):
            grid[i][j]=1
            if maze(grid, i, c):
                return True
            grid[i][j]=0
    return False
            
            
def helper(grid, i, j):
    if i<0 or j<0 or i>=len(grid) or j>=len(grid[0]):
        return
    if grid[i][j]==1:
        return
    return True

print(maze([[0,1,1],
            [0,0,1],
            [1,0,0]], 0, 0))

print(maze([[0,1,1,1,1,1,1],
            [0,0,1,1,0,1,1],
            [1,0,0,0,0,0,1], 
            [1,1,1,1,1,0,1],
            [1,1,1,1,1,0,0]], 0, 0))

print(maze([[0,1,1,1,1,1,1],
            [0,0,1,0,0,1,1],
            [1,0,0,0,0,1,1], 
            [1,1,0,1,0,1,0],
            [1,1,0,0,1,1,0]], 0, 0))

print(maze([[0,1,1,1,1,1,0],
            [0,0,0,1,0,0,0],
            [1,0,1,0,0,1,0],
            [1,0,0,0,0,1,0],
            [1,1,1,1,1,1,0]], 0, 0))


end_time = time.time()

# Time taken in seconds
time_taken = end_time - start_time
print(time_taken)
