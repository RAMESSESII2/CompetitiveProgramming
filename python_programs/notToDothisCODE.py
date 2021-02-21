from time import time
start_time = time()

import numpy as np

def diagonalize(n: int, corner: str):
    if n==0:
        return []
    if n==1:
        return [0]

    grid=[[0 for i in range(n)] for j in range(n)]
    t=n
    if corner=="ul":
        i=j=0
        while(i<t-1 and j<t-1):
            grid[i+1][j+1]=grid[i][j]+2
            for v in range(j,t-1):
                grid[i][v+1]=grid[i][v]+1
            if i<t and j>0:
                for v in range(j, 0, -1):
                    grid[i][v-1]=grid[i][v]-1
            i+=1
            j+=1
        for j in range(t-1,0,-1):
            grid[i][j-1]=grid[i][j]-1
    if corner=="ur":
        i=0
        j=n-1
        while(i<t and j>0):
            i+=1
            j-=1
            grid[i][j]=grid[i-1][j+1]+2
            for v in range(j,t-1):
                grid[i][v+1]=grid[i][v]-1
            if i>0 and j<t:
                for v in range(j, 0, -1):
                    grid[i][v-1]=grid[i][v]+1
        for j in range(t-1, 0, -1):
            grid[0][j-1]=grid[0][j]+1
        
    if corner=="ll":
        i=n-1
        j=0
        while(i>0 and j<t-1):
            for v in range(j,t-1):
                grid[i][v+1]=grid[i][v]+1
            if i>0 and j<t:
                for v in range(j, 0, -1):
                    grid[i][v-1]=grid[i][v]-1
            i-=1
            j+=1
            grid[i][j]=grid[i+1][j-1]+2
        for j in range(t-1, 0, -1):
            grid[0][j-1]=grid[0][j]-1


    
    if corner=="lr":
        i=j=n-1
        while(i>0 and j>0):
            for v in range(j,t-1):
                grid[i][v+1]=grid[i][v]-1
            if i>0 and j<t:
                for v in range(j, 0, -1):
                    grid[i][v-1]=grid[i][v]+1
            grid[i-1][j-1]=grid[i][j]+2
            i-=1
            j-=1
        for j in range(0, t-1):
            grid[0][j+1]=grid[0][j]-1
    

    return np.matrix(grid)


print(diagonalize(4, "ul"))
print(diagonalize(8, "ll"))
print(diagonalize(4, "ur"))
print(diagonalize(5, "lr"))
print(diagonalize(6, "lr"))

passed_time = time() - start_time
print(f"It took {passed_time}")