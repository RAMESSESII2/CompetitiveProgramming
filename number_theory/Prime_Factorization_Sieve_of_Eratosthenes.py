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
    factors=[0]*(n+1)
    prime_factors={}
    # for i in range(2, n+1):
    #     factors[i]=0
    x=n
    #x=45
    while(x>1):
        factors[largest_prime[x]]+=1
        #factors[largest_prime[45]=5]=1
        prime_factors[largest_prime[x]]=factors[largest_prime[x]]

        x=x//largest_prime[x]

    return prime_factors

print(prime_factorisation(2))
print(prime_factorisation(3))
print(prime_factorisation(4))
print(prime_factorisation(5))
print(prime_factorisation(6))
print(prime_factorisation(7))
print(prime_factorisation(120))
print(prime_factorisation(2000))
print(prime_factorisation(30000))
print(prime_factorisation(400000))
""" 
outputs
{2: 1}
{3: 1}
{2: 2}
{5: 1}
{3: 1, 2: 1}
{7: 1}
{5: 1, 3: 1, 2: 3}
{5: 3, 2: 4}
{5: 4, 3: 1, 2: 4}
{5: 5, 2: 7}
"""


end_time = time.time()
# Time taken in seconds
time_taken = end_time - start_time
print(time_taken)
