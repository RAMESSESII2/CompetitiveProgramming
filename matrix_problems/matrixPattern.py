from time import time
start_time = time()
import numpy as np

def matrix(x):
    if x==0:
        return [] 
    if x==1:
        return 0
    l=[[0 for i in range(x)] for i in range(x)]
    mid=x//2
    rug(l, mid-1, mid+1)
    return l

def rug(L, l, h):
    if l<0 or h>len(L)-1:
        return 
    for i in range(l, h+1):
        for j in range(l, h+1):
            if i==len(L)//2 and j==len(L)//2:
                continue
            if L[i][j]==0:
                L[i][j]=L[l+1][l+1]+1
    rug(L, l-1, h+1)
    return L

    

print(np.matrix(matrix(6)))

passed_time = time() - start_time
print(f"It took {passed_time}")