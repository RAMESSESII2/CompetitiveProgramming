s = "thiscanbeasub"
t = "isthisdjkjfksjdkcfjdkub"
dp = [[-1]*(len(t)+1)]*(len(s)+1)

def lcs(s, t, ls, lt):
    if ls == 0 or lt == 0:
        return 0
    if dp[ls][lt] != -1:
        return dp[ls][lt]

    if s[ls-1]== t[lt-1]:
        dp[ls][lt] = 1 + lcs(s, t, ls-1, lt-1)
    else:
        dp[ls][lt] =max(lcs(s, t, ls, lt-1), lcs(s, t, ls-1, lt))
        
    return dp[ls][lt]


print(lcs(s, t, len(s), len(t)))
