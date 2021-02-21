# You are given an integer n. On each step, you may substract from it any one-digit number that appears in it.

# How many steps are required to make the number equal to 0?
import sys
from functools import lru_cache
# sys.setrecursionlimit(15000)
# @lru_cache(128)
#@lru_cache
sys.stdout = open("out.txt", "w")
sys.stdin = open("in.txt", "r")



# @lru_cache
# def solver(n, count):
#     if n == 0:
#         return count
#     if dp[n] != -1:
#         return dp[n]
#     p = n
#     minm = float("inf")
#     while p > 0:
#         if p % 10 != 0:
#             dp[n] = solver(n - (p % 10), count + 1)
#             if minm > dp[n]:
#                 minm = dp[n]
#         p = p // 10
#     return minm


# if __name__ == "__main__":
#     for i in range(int(input())):
#         N = int(input())
#         # pc pr = map(int input().split())
#         # arr = list(map(intinput().split()))
#         dp = [-1 for _ in range(N + 1)]
#         print(solver(N, 0))

# ""solution based on minimizing_coins_dp.py""
def solver(x):
    dp = [float("inf") for _ in range(x + 1)]
    dp[0] = 0
    for j in range(1, x + 1):
        k = j
        for i in range(len(str(j))):
            if k % 10 == 0:
                k = k // 10
                continue
            dp[j] = min(dp[j], 1 + dp[j - (k % 10)])
            k = k // 10
    if dp[x] == float("inf"):
        return -1
    return dp[x]


if __name__ == "__main__":
    # for i in range(int(input())):
    N = int(input())
    # X = int(input())
    print(solver(N))
