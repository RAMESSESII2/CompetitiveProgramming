# input for test cases
tc=int(input())
tt={}
for t in range(1,tc+1):
    #input for no.s in array N and K
    N,K=(input().split())
    #input for positive integer in N
    l=[]
    l = list(map(int,input().strip().split()))[:int(N)]
    def NoCountD(L:list, K:int)->int:
        count=1
        k=0
        for i,val in enumerate(L):
            if count==3 and i<len(L)-1 and val-L[i+1]!=1:
                k+=1
            if i<len(L)-1 and val-L[i+1]==1:
                count+=1
            else:
                count=1
        return k 
    tt[t]=str(NoCountD(l ,K))
for i in range(1,tc+1):
    print("Case #"+str(i)+": "+tt[i])
# print(NoCountD([100,99,98,32,31,30,0,1,3,2,1,0,5,4,3,2], 3))
# print(NoCountD([0], 0))

