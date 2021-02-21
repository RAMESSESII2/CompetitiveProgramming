# Consider an n×n grid whose squares may have traps. It is not allowed to move to a square with a trap.

# Your task is to calculate the number of paths from the upper-left square to the lower-right square where you only can move right or down.

# import time

# start_time = time.time()
# import sys

# sys.stdout = open("out.txt", "w")
# sys.stdin = open("in.txt", "r")

# import os
# import math
# import numpy as np
# from collections import OrderedDict
# from memo import memo #@memo
# from collections import deque #list = deque()
# import random
# from queue import *

# from functools import lru_cache #@lru_cache
# from functools import lru_cache
# sys.setrecursionlimit(15000)
# @lru_cache(128)


def solver(arr, n):
    dp = [[0 for _ in range(n)] for _ in range(n)]
    mod = 10 ** 9 + 7
    if arr[n - 1][n - 1] == "*":
        return -1
    dp[n - 1][n - 1] = 1
    # last coulumn of cell filled first
    for i in range(n - 2, -1, -1):
        if arr[i][n - 1] == "*":
            dp[i][n - 1] = 0
        else:
            dp[i][n - 1] += dp[i + 1][n - 1]
    for i in range(n - 2, -1, -1):
        if arr[n - 1][i] == "*":
            dp[n - 1][i] = 0
        else:
            dp[n - 1][i] += dp[n - 1][i + 1]

    for i in range(n - 2, -1, -1):
        for j in range(n - 2, -1, -1):
            if arr[i][j] == "*":
                dp[i][j] = 0
            else:
                dp[i][j] += (dp[i + 1][j] % mod + dp[i][j + 1] % mod) % mod
    return dp[0][0]


if __name__ == "__main__":
    # for i in range(int(input())):
    n = int(input())
    # pc pr = map(int, input().split())
    arr = [[None for _ in range(n)] for _ in range(n)]
    for i in range(n):
        arr[i] = list(input())
    print(solver(arr, n))


# end_time = time.time()

# # Time taken in seconds
# time_taken = end_time - start_time
# print(time_taken)
# input

# 4
# ....
# .*..
# ...*
# *...

# output

# 3
# 0.0001513957977294922
