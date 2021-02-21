""" from time import time
start_time = time()
import numpy as np

wt = [2, 1, 8, 5, 6]
W = 9


def evaluate(W, n):
    dp = [[False] * (W + 1)] * (n + 1)

    for i in range(n + 1):
        dp[i][0] = True
    for i in range(1, n + 1):
        for j in range(1, W + 1):
            if j < wt[i - 1]:
                dp[i][j] = dp[i - 1][j]
            if j >= wt[i - 1] :
                dp[i][j] = (dp[i - 1][j] or dp[i-1][j - wt[i - 1]])

    return dp[n][W], np.matrix(dp)

n = len(wt)
print(evaluate(W, n))


passed_time = time() - start_time
print(f"It took {passed_time}")
 """

def isSubsetSum(set, n, sum): 
      
    # The value of subset[i][j] will be  
    # true if there is a 
    # subset of set[0..j-1] with sum equal to i 
    subset =([[False for i in range(sum + 1)]  
            for i in range(n + 1)]) 
      
    # If sum is 0, then answer is true  
    for i in range(n + 1): 
        subset[i][0] = True
          
    # If sum is not 0 and set is empty,  
    # then answer is false  
    for i in range(1, sum + 1): 
         subset[0][i]= False
              
    # Fill the subset table in botton up manner 
    for i in range(1, n + 1): 
        for j in range(1, sum + 1): 
            if j<set[i-1]: 
                subset[i][j] = subset[i-1][j] 
            if j>= set[i-1]: 
                subset[i][j] = (subset[i-1][j] or 
                                subset[i - 1][j-set[i-1]]) 
      
    # uncomment this code to print table  
    # for i in range(n + 1): 
    # for j in range(sum + 1): 
    # print (subset[i][j], end =" ") 
    # print() 
    return subset[n][sum] 
          
# Driver program to test above function 
if __name__=='__main__': 
    set = [3, 34, 4, 12, 5, 2] 
    sum = 9
    n = len(set) 
    if (isSubsetSum(set, n, sum) == True): 
        print("Found a subset with given sum") 
    else: 
        print("No subset with given sum") 