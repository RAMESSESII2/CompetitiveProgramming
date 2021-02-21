""" from time import time
start_time = time()
import numpy as np

wt = [2, 1, 8, 5, 6]
wt.sort()
W = 9


def evaluate(wt, W, n):
    dp = [[0] * (W + 1)] * (n + 1)
    for i in range(1, W + 1):
        dp[0][i] = False
    for i in range(n + 1):
        dp[i][0] = True
    for i in range(1, n + 1):
        for j in range(1, W + 1):
            if wt[i - 1] <= j:
                dp[i][j] = (dp[i - 1][j] or dp[i-1][j - wt[i - 1]])
            else:
                dp[i][j] = dp[i - 1][j]
    return dp[n][W], np.matrix(dp)

n = len(wt)
    print(evaluate(wt, W, n))


passed_time = time() - start_time
print(f"It took {passed_time}") """


def isSubsetSum(set, n, summ): 
      
    # The value of subset[i][j] will be  
    # true if there is a 
    # subset of set[0..j-1] with summ equal to i 
    subset =([[False for i in range(summ + 1)]  
            for i in range(n + 1)]) 
      
    # If summ is 0, then answer is true  
    for i in range(n + 1): 
        subset[i][0] = True
          
    # If summ is not 0 and set is empty,  
    # then answer is false  
    for i in range(1, summ + 1): 
         subset[0][i]= False
              
    # Fill the subset table in botton up manner 
    for i in range(1, n + 1): 
        for j in range(1, summ + 1): 
            if j<set[i-1]: 
                subset[i][j] = subset[i-1][j] 
            if j>= set[i-1]: 
                subset[i][j] = (subset[i-1][j] or 
                                subset[i - 1][j-set[i-1]]) 
      
    # uncomment this code to print table  
    minmdifference = 34798
    for i in range(1, (summ +1)//2):
        if subset[n][i] == True:
            minmdifference = min(minmdifference, summ - (2*i))

    return subset[n], minmdifference
          
# Driver program to test above function 
if __name__=='__main__': 
    set = [3, 17, 4, 12, 5, 2] 
    summ = sum(set)
    n = len(set) 
    print(isSubsetSum(set, n, summ))
