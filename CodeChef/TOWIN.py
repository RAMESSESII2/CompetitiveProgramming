if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        arr = list(map(int, input().split()))
        # if n==1:
        #     print("first")
        #     break
        for i in range(4):
            arr.append(0)
        evensum=sum(arr[0::2])
        oddsum=sum(arr[1::2])
        if oddsum>evensum:
            print("second")
        # 6
        # 1 3 1 5 6 2 4 5 2
        # e   e   e   e   e

        elif arr[0]+sum(arr[3::2])>arr[1]+arr[2]+sum(arr[4::2]):
            print("first")
        elif arr[0] + sum(arr[3::2]) < arr[1] + arr[2] + sum(arr[4::2]):
            print("second")
        elif evensum>oddsum:
            print("first")
        else:
            print("draw")

""" for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    l=sorted(l)
    r=l[::-1]
    
    if(n==1 or n==2):
        print("first")
    else:
        p1=r[1]+sum(r[2::2])
        p2=sum(l)-p1
    
        if(p1>p2):
            print("second")
        elif(p2>p1):
            print("first")
        else:
            print("draw") """