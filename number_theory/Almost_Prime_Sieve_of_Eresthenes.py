#x,ximport sys
# sys.stdout = open('CP/output.txt', 'w')
# sys.stdin = open('CP/input.txt', 'r')

if __name__=='__main__':
    N = int(input())
    if N < 5:
        print(0)
    else:
        primes = [0]*(N+1)
        for i in range(2, N+1):
            if primes[i] == -1:
                continue
            primes[i] = i
            for j in range(2*i, N+1, i):
                primes[j] = -1    
        a = [i for i in range(N+1)]
        ap = 0
        for i in range(2, N+1):
            count = 0
            if a[i] != -1:
                for j in primes[2:]:
                    if j != -1 and a[i] % j == 0:
                        count +=1 
                    if count > 2:
                      break
            if count == 2:
                ap +=1  
            if primes[i]!= -1:
                a[i] = -1
                j = 2
                while(N//(i**j) > 0):
                    a[i**j] = -1
                    j += 1
        print(ap)                    
            

        
