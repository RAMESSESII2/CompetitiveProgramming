def lcs(x, y, ls, lt):
    dp = [[0]*(lt+1)]*(ls+1)
    res = 0
    for i in range(ls+1):
        for j in range(lt+1):
            if (i == 0 or j == 0):
                dp[i][j] = 0 
            elif (x[i-1] == y[j-1]):
                dp[i][j] = dp[i-1][j-1] + 1
                res = max(res, dp[i][j])
            else:
                dp[i][j] = 0 
    return res

x = 'OldSiteGeeksforGeeksorg'
y = 'NewSiteGeeksQuizcom'
m = len(x)
n =len(y)
print(lcs(x, y, m, n))
