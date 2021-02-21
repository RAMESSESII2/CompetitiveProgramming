import numpy as np
grid=   [[0,0,0, 0,0,0, 0,0]
        ,[0,0,0, 0,0,0, 0,0]
        ,[0,0,0, 0,0,0, 0,0]
        ,[0,0,0, 0,0,0, 0,0]
        ,[0,0,0, 0,0,0, 0,0]
        ,[0,0,0, 0,0,0, 0,0]
        ,[0,0,0, 0,0,0, 0,0]
        ,[0,0,0, 0,0,0, 0,0]]
print("Where do you want to put your first queen")
# a,b=input("Specify row and column").split(" ")
# a,b =int(a), int(b)
# grid[0][1]=1
print(np.matrix(grid))

def possible(r, c):
    global grid
    for i in range(8):
        if grid[r][i]==1:
            return False
    for i in range(8):
        if grid[i][c]==1:
            return False
    i,j=r,c
    while(i>=0 and j>=0):
        if grid[i][j]==1:
            return False
        i-=1
        j-=1
    i,j=r,c
    while(i<8 and j>=0):
        if grid[i][j]==1:
            return False
        i+=1
        j-=1
    i,j=r,c
    while(i>=0 and j<8):
        if grid[i][j]==1:
            return False
        i-=1
        j+=1
    i,j=r,c
    while(i<8 and j<8):
        if grid[i][j]==1:
            return False
        i+=1
        j+=1
    return True
print(possible(0,0))

def EQueensSolver(c):
    global grid
    for i in range(8):
        if possible(i,c):
            grid[i][c]=1
            if EQueensSolver(c+1):
                return True
            grid[i][c]=0
    print(np.matrix(grid))
    input("More?")
print(EQueensSolver(0))
    