
def  subarray(arr, i, n):
    if not arr:
        return 0
    global count
    if i<0:
        return count
    count+=1

    if i<len(arr)-1:
        if arr[i+1]>=arr[i]:
            count+=n
            n+=1
        else:
            n=1
    subarray(arr, i-1, n)
    return count

T=int(input())
for i in range(T):
    N=int(input())
    arr = list(map(int,input().split())) 
    count=0
    n=1
    print(subarray(arr, N-1, n))
