W = 25
wt = [5, 10, 15]
val = [10, 30, 20]

""" 
we can use 100 units of wt 1 to get W=100
reach the targeted wt. with maxm value possible
 states wil be p->value
 dp[0]=0
 """
def unboundedJ(v, wt, W, n):
    dp = [0]*(W+1)
    for i in range(1, W+1):
        for j in range(n):
            if i>=wt[j]:
                dp[i] = max(dp[i], dp[i-wt[j]]+v[j])
    return dp[W]

print(unboundedJ(val, wt, W, len(val)))
