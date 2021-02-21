# The edit distance between two strings is the minimum number of operations required to transform one string into the other.

# The allowed operations are:

#     Add one character to the string.
#     Remove one character from the string.
#     Replace one character in the string.

# For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.

import sys

sys.stdout = open("out.txt", "w")
sys.stdin = open("in.txt", "r")


def solver(n, m):
    dp = [[0 for i in range(len(m) + 1)] for j in range(len(n) + 1)]
    for i in range(len(n) + 1):
        dp[i][0] = i
    for i in range(len(m) + 1):
        dp[0][i] = i
    for i in range(1, len(n) + 1):
        for j in range(1, len(m) + 1):
            if n[i - 1] == m[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1
    return dp[len(n)][len(m)]


if __name__ == "__main__":
    n = sys.stdin.readline()
    m = sys.stdin.readline()
    print(solver(n, m))


# Input

# LOVE
# MOVIE

# oOUUTput
# 2
