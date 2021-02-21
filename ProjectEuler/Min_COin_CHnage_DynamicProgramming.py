import time
start_time = time.time()

w=[2,5,10]
n=3
S=18
dp=[0]*(S+1)
def iterative(w,S):
    # dp[0]=0
    tep=0
    P=1
    while(P<=S):
        minm = float("inf")
        for x in w:
            if x<=P:
                tep=(dp[P-x])+1
            minm = min(minm, tep)
        
        dp[P]=minm
        P+=1
    return dp,dp[S]

print(iterative(w,S))


end_time = time.time()
# Time taken in seconds
time_taken = end_time - start_time
print(time_taken)
