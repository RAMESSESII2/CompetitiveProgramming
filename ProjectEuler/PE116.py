# import time
# start_time = time.time()

# import math
# import numpy as np
# from functools import lru_cache

# def main(n):
#     dp=[[0]*(n+1)]*(n+1)
#     total=0
#     for size in [2,3,4]:
#         for num in range(1, (n//size)+1):
#             dp[size][num]=perm(num, size, n)
#             total+=perm(num, size, n)
#     return total

# def perm(num, size, n):
#     entity=n-(num*size)+num
#     permutations=fact(entity)//((fact(num))*fact(entity-num))
#     return permutations

# def fact(n):
#     if n==0 or n==1:
#         return 1    
#     f=1
#     for i in range(1, n+1):
#         f=f*i
#     return f
        
# print(main(50))

#SLower
@lru_cache
def G(m, n):
    if m>n:
        return 1
    else:
        return G(m, n-1)+G(m, n-m)

print(G(2,50)+G(3,50)+G(4,50)-2)

end_time = time.time() 
# Time taken in seconds
time_taken = end_time - start_time
print(time_taken)


