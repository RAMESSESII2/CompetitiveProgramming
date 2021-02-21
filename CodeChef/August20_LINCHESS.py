
if __name__=='__main__':
    T = int(input())
    for i in range(T):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        largest=-1
        for x in arr:
            if k%x==0:
                largest=max(x,largest)
        print(largest)