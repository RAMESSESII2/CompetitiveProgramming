weight = [1, 2, 3, 4]
value = [10, 30, 10, 10]
W = 7

""" #naive recursive approach
def evalt(v, w, W, n):
    if n==0 or W==0:
        return 0
    if w[n-1]>W:
        return evalt(v, w, W, n-1)
    return max(evalt(v, w, W-w[n-1], n-1)+v[n-1], evalt(v, w, W, n-1))

print(evalt(value, weight, W, len(value)))
 """

def evalt(v, wt, W, n):
    dp = [[-1] * (W + 1)] * (n + 1)
    if n== 0 or W == 0:
        dp[n][W]=0
        return dp[n][W]
    if dp[n][W] !=-1:
        return dp[n][W]
    if wt[n-1] > W:
        dp[n][W] = evalt(v, wt, W, n - 1)
        return (dp[n][W])
    else:
        dp[n][W] = max(evalt(v, wt, W - wt[n-1], n - 1) + v[n-1], evalt(v, wt, W, n - 1))
        return dp[n][W]
    """ for i in range(n+1):
        for w in range(W+1):
            if i==0 or w==0:
                dp[i][w] = 0
            elif wt[i-1]<=w:
                dp[i][w] = max(v[i-1] + dp[i-1][w - wt[i-1]],dp[i - 1][w])
            else:
                dp[i][w] = dp[i-1][w]
    return dp[n][W] """

print(evalt(value, weight, W, len(value)))