# Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.

# For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:

#     2+2+5


# 3+3+3

# 2+2+2+3

import sys

sys.stdout = open("out.txt", "w")
sys.stdin = open("in.txt", "r")

# import os
# import math
# import numpy as np
# from collections import OrderedDict
# from memo import memo #@memo
# from functools import lru_cache #@lru_cache
# from collections import deque #list = deque()
# import random
# from queue import *


def solver(coin, x):
    mod = 10 ** 9 + 7
    dp = [0 for _ in range(x + 1)]
    dp[0] = 1
    for i in range(len(coin)):
        for j in range(1, x + 1):
            if j >= coin[i]:
                dp[j] = (dp[j] % mod + dp[j - coin[i]] % mod) % mod
    return dp[x]


if __name__ == "__main__":
    # for i in range(int(input())):
    # N = int(input())
    # X = int(input())
    N, X = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    print(solver(arr, X))
