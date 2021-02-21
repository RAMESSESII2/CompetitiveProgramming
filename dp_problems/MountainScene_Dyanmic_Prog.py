from time import time
start_time = time()
import math
 
mod=100000007
N,W,H=4, 2,2
sqribbons=min(N, W*H)
dp = [[None]*(W+1)]*(W*H+1)
def solve():
    plainscenes=(sqribbons//W)+1
    return ((f(1,sqribbons)-plainscenes)+mod)%mod

def f(w, ribbons):
    if ribbons<0:
        return 0
    if w>W:
        return 1
    if dp[w-1][ribbons-1]!= None:
        return dp[w-1][ribbons-1]
    scenes=0
    for len in range(0, H+1):
        scenes=(scenes+f(w+1,ribbons-len))
    dp[w-1][ribbons-1] = (scenes%mod)
    return dp[w][ribbons]

print(solve())

passed_time = time() - start_time
print(f"It took {passed_time}")