import numpy as np
m, n = 3, 50
ways = [1]*(m) + [0]*(n-m+1)
for k in range(m, n+1):
	ways[k] = ways[k-1] + sum(ways[:k-m]) + 1


print ("Minimum block size =", m, "units")
print ("A space", n, "units long can be filled\n", ways[n], "ways")

"""
#wrong
 def ways(n,m):
		dp = [[0]*(n+1)]*(n+1)
		for i in range(0, m):
			dp[i][m] = 1
		for j in range(m,n+1):
			if n-m-1<0:
				dp[n][m] = 2*dp[n-1][m] - dp[n-2][m] + 1
			else:
				dp[n][m] = 2*dp[n-1][m] - dp[n-2][m] + dp[n-m-1][m] 
		return dp

print(np.matrix(ways(4,3))) """
""" 
 """