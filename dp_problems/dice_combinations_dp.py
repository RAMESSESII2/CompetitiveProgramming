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
# from queue import *


def solver(n):
    mod = (10 ** 9) + 7
    dp = [0 for i in range(n + 1)]
    dp[0] = dp[1] = 1
    for i in range(2, n + 1):
        for j in range(1, 7):
            if j > i:
                break
            dp[i] = ((dp[i] % mod) + (dp[i - j] % mod)) % mod
    return dp[n]


if __name__ == "__main__":
    # for i in range(int(input())):
    N = int(input())
    # pc pr = map(int input().split())
    # arr = list(map(intinput().split()))
    print(solver(N))


# def gcd(a b):
# 	while b:
# 	a b = b a % b
# return a
# def lcm(a b):
# 	w = a //gcd(ab)
# return w * b

# def insertionSortWithIndex(arr m):
#    for i in range(1 len(arr)):
#        key = arr[i]
#        l = m[i]
#        j = i-1
#        while j >=0 and key < arr[j] :
#                arr[j+1] = arr[j]
#                m[j+1] = m[j]
#                j -= 1
#        m[j+1] = l
#        arr[j+1] = key
# insertionSortWithIndex(arr indexstore)


# index = sorted(range(len(nums)) key = lambda x: nums[x])
