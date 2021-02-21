""" import sys
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


def recurse(dic, family, n, k, minm):
    if n==len(family):
        return minm
    if family[n] not in [*dic]:
        # print(dic)
        dic[family[n]] = 1
        return recurse(dic, family, n+1, k, minm)
    else:
        dic[family[n]] += 1
        minm += 1
        nminm = minm + k
        ndic = {}
        if dic[family[n]] == 2:
            minm += 1

        # print(dic, minm, ndic, nminm)
        return min(recurse(ndic, family, n+1, k, nminm), recurse(dic, family, n+1, k, minm))


if __name__=='__main__':
    for i in range(int(input())):
        n, k = map(int, input().split())
        arr = list(map(int,input().split()))
        print(recurse({}, arr, 0, k, k)) """
#include<bits/stdc++.h>
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
/*Author : Darshan Lokhande*/
/*Complexity of Soln : O(n^2)*/

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int f[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> f[i];

        //dp[i] will store minimum inefficiency for seating first i people
        int dp[n + 1];
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + k;  //seperate table for ith person
            map <int, int> mp;
            int clash = 0;

            /* try out all possible options that include ith person as last person
               on the table */
            for (int j = i; j >= 1; j--)
            {
                mp[f[j]]++;
                if (mp[f[j]] == 2)
                    clash += 2;
                else if (mp[f[j]] > 2)
                    clash += 1;

                //update dp[i] if you find a lower inefficiency value
                dp[i] = min(dp[i], dp[j - 1] + k + clash);
            }
        }
        cout << dp[n] << '\n';
    }

    return 0;
}