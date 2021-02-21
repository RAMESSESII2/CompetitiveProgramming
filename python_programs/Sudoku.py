from time import time
start_time = time()

import numpy as np
grid=   [[5,3,0, 0,7,0, 1,0,0]
        ,[6,0,0, 1,9,5, 0,0,0]
        ,[0,9,8, 0,0,0, 0,6,0]
        ,[8,0,0, 7,6,1, 0,0,3]
        ,[4,0,0, 8,0,0, 0,0,1]
        ,[7,0,0, 0,3,0, 0,0,6]
        ,[0,6,0, 0,0,0, 2,8,0]
        ,[0,0,0, 4,1,9, 0,0,5]
        ,[3,1,6, 5,8,0, 4,7,9]]
#print(np.matrix(grid))

def possibleAt(y, x, n):
    global grid
    for i in range(9):
        if grid[y][i]==n:
            return False
    for i in range(9):
        if grid[i][x]==n:
            return False
    x0=(x//3)*3
    y0=(y//3)*3
    for i in range(3):
        for j in range(3):
            if grid[y0+i][x0+i]==n:
                return False
    return True

def sudoku():
    global grid
    for y in range(9):
        for x in range(9):
            if grid[y][x]==0:
                for n in range(1,10):
                    if possibleAt(y, x, n):
                        grid[y][x]=n
                        sudoku()
                        grid[y][x]=0
                return
    print(np.matrix(grid))
    # input("more?")
sudoku()

passed_time = time() - start_time
print(f"It took {passed_time}")