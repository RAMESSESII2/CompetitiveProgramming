import math

def wars(H, P):
    while(P>0):
        H=H-P
        if H<=0:
            return 1
        P>>=1
    return 0


T = int(input())
for i in range(T):
    arr = list(map(int, input().split()))
    print(wars(arr[0], arr[1]))