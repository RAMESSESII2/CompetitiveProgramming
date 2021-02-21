import time
start_time = time.time()

def prime_factorisation(n):
    largest_prime=[0]*(n+1)
    for i in range(2,n+1):
        if largest_prime[i]!=0:
            continue
        largest_prime[i]=i
        for j in range(2*i, n+1, i):
            largest_prime[j]=i

    # i=2, largest_prime[2]=2, j=4,n+1,j+=i
    #                              largest_prime[4]=2
    #                              largest_prime[6]=3 // gets updated every step
    
    prime_factors={}
    for i in range(2, n+1):
        factors=[0]*(n+1)
        x=i
        #x=45
        # dic={12:{2:2, 3:1}}
        prime_factors[i]={}
        while(x>1):
            factors[largest_prime[x]]+=1         
            #factors[largest_prime[45]=5]=1
            prime_factors[i][largest_prime[x]]=(factors[largest_prime[x]])

            x=x//largest_prime[x]
    A=[0]*(n+1)
    for i in range(2,n+1):
        count=0
        for j in [*prime_factors[i]]:
            count+=1
        A[i]=count
    return A

def Kprimes(a,b,k):
    A=prime_factorisation(b)
    prefix=[[0]*5]*(b+1)
    for i in range(a-1, b+1):
        for j in range(1, 5):
            if A[i]==j:
                prefix[i][j]=prefix[i-1][j]+1
            else: 
                prefix[i][j]=prefix[i-1][j]+0
    return (prefix[b][k])

T=int(input())
for i in range(T):
    arr = list(map(int,input().split())) 
    print(Kprimes(arr[0], arr[1], arr[2]))
""" 
4
2 5 1
4 10 2
14 15 2
2 20 3
 """

# print(prime_factorisation(2))    
# print(prime_factorisation(3))    
# print(prime_factorisation(4))    
# print(prime_factorisation(5))    
# print(prime_factorisation(6))    
# print(Kprimes(2,4,1))    
# print(prime_factorisation(120))    
# print(prime_factorisation(2000))    
# print(prime_factorisation(30000))    
# print(prime_factorisation(100000))    


end_time = time.time()
# Time taken in seconds
time_taken = end_time - start_time
print(time_taken)
