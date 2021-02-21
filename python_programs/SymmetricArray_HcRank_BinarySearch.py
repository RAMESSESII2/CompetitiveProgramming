import sys
sys.stdout = open('CP/output.txt', 'w')
sys.stdin = open('CP/input.txt', 'r')

import os
import math
import numpy as np
from collections import OrderedDict
from memo import memo #@memo
from functools import lru_cache #@lru_cache
from collections import deque #list = deque()
import random
from queue import *

#def gcd(a, b):
#	while b:
#	a, b = b, a % b
#return a
#def lcm(a, b):
#	w = a //gcd(a,b)
#return w * b
def binary_search(P, array) -> int:
    def condition(value) -> bool:
        return (len(array)*(math.log(value))) > P
    left, right = 1, max(array)+1
    while left < right:
        mid = left + (right - left) // 2
        if condition(mid):
            right = mid
        else:
            left = mid+1
    return left

if __name__=='__main__':
    N = int(input())
    arr = list(map(int, input().split()))
    #pc, pr = map(int, input().split())
    l=list(map(lambda x: math.log(x), arr))
    P=(sum(l))
    # if P==0:
    #     print(1)
    # else:
    print(binary_search(P, arr))
