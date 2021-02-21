# You know that an array has n integers between 1 and m, and the difference between two adjacent values is at most 1.
# Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.
import sys

# sys.stdout = open("out.txt", "w")
# sys.stdin = open("in.txt", "r")


def solver(n, m, arr):
    mod = 10 ** 9 + 7
    dp = [[0 for i in range(0, n)] for _ in range(0, m + 1)]
    for i in range(n):
        if i == 0:
            if arr[i] != 0:
                dp[arr[i]][i] = 1
            else:
                j = 1
                while j < m + 1:
                    dp[j][i] = 1
                    j += 1
            continue
        if arr[i] != 0:
            dp[arr[i]][i] = (
                dp[arr[i] - 1][i - 1] % mod
                + dp[arr[i]][i - 1] % mod
                + (dp[arr[i] + 1][i - 1] % mod if (arr[i] + 1 < m + 1) else 0)
            ) % mod
        if arr[i] == 0:
            j = 1
            while j < m + 1:
                dp[j][i] = dp[j][i - 1]
                if j > 1:
                    dp[j][i] = dp[j - 1][i - 1] % mod + dp[j][i] % mod
                if j < m:
                    dp[j][i] = dp[j + 1][i - 1] % mod + dp[j][i] % mod
                dp[j][i] %= mod
                j += 1
    if arr[n - 1] != 0:
        return dp[arr[n - 1]][n - 1] % mod
    else:
        result = 0
        for j in range(1, m + 1):
            result %= mod
            result += dp[j][n - 1] % mod
        return result % mod


if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    arr = list(map(int, sys.stdin.readline().split()))
    print(solver(n, m, arr))


# input

# 3 5
# 2 0 2

# output
# 3
