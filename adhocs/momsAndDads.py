import sys
sys.stdout = open('out.txt', 'w')
sys.stdin = open('in.txt', 'r')
import os
import math
# import numpy as np
# from collections import OrderedDict
# from memo import memo #@memo
# from collections import deque #list = deque()
# impprt random
# from queue import * 

# from functools import lru_cache #@lru_cache
# from functools import lru_cache
# sys.setrecursionlimit(15000)
# @lru_cache(128)


def solver( m, n, s, cur ):
    dp = [[0]*(n+1) for i in range(m+1)]

    for i in range(n+1): dp[0][i] = 0
    for i in range(m+1): dp[i][0] = 1
    for i in range(1, m+1):
        for j in range(1, n+1):
            if s[i-1] == cur[j-1]:
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j]
    return dp[m][n]

if __name__ == '__main__':
    # for i in range(int(input())):
    s = (sys.stdin.readline())
    # s = input();
    # arr = [[None for _ in range(n)] for _ in range(n)]
    # for i in range(n):
    #     arr[i] = list(sys.stdin.readline())
    ans = solver(len(s), 3, s, "MOM") + solver(len(s), 3, s, "DAD")
    sys.stdout.write(str(ans))
    # print(str(ans))
