# import sys

# sys.stdout = open("out.txt", "w")
# sys.stdin = open("in.txt", "r")

# import os
# import math
# import numpy as np
# from collections import OrderedDict
# from memo import memo #@memo
# from functools import lru_cache #@lru_cache
# from collections import deque #list = deque()
# import random


def solver(coin, x):
    dp = [float("inf") for _ in range(x + 1)]
    dp[0] = 0
    for j in range(1, x + 1):
        for i in range(len(coin)):
            if j >= coin[i]:
                dp[j] = min(dp[j], 1 + dp[j - coin[i]])
    if dp[x] == float("inf"):
        return -1
    return dp[x]


if __name__ == "__main__":
    # for i in range(int(input())):
    # N = int(input())
    # X = int(input())
    N, X = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    print(solver(arr, X))
