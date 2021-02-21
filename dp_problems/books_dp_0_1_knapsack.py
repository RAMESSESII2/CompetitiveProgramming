# You are in a book shop which sells n different books. You know the price and number of pages of each book.
# You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.

import sys

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


def solver(price, pages, x, n):
    # dp = [[0 for _ in range(x + 1)] for _ in range(n + 1)]
    a = [0 for _ in range(x + 1)]
    b = [0 for _ in range(x + 1)]
    for i in range(1, n + 1):
        for j in range(1, x + 1):
            if j >= price[i - 1]:
                b[j] = max(a[j], a[j - price[i - 1]] + pages[i - 1])
                # dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price[i - 1]] + pages[i - 1])
            else:
                b[j] = a[j]
                # dp[i][j] = dp[i - 1][j]
        for k in range(x + 1):
            a[k] = b[k]
    # return dp[n][x]
    return b[x]


if __name__ == "__main__":
    # for i in range(int(input())):
    # n = int(input())
    pc, pr = map(int, sys.stdin.readline().split())
    price = list(map(int, sys.stdin.readline().split()))
    pages = list(map(int, sys.stdin.readline().split()))

    # arr = [[None for _ in range(n)] for _ in range(n)]
    # for i in range(n):
    #     arr[i] = list(input())

    print(solver(price, pages, pr, pc))


# Input

# 4 10
# 4 8 5 3
# 5 12 8 1

# OUtput
# 13
