import math
def btfl(arr):
    count=0
    for i in range(len(arr)):
        for j in range(i+1,len(arr)):
            for k in range(j+1,len(arr)):
                if arr[j][2]==int(math.sqrt(((arr[i][0]-arr[k][0])**2)+((arr[i][1]-arr[k][1])**2))):
                    if int(math.sqrt(((arr[i][0]-arr[k][0])**2)+((arr[i][1]-arr[k][1])**2)))//2<arr[i][3] or int(math.sqrt(((arr[i][0]-arr[k][0])**2)+((arr[i][1]-arr[k][1])**2)))<arr[k][3]:
                        count+=1
    return count


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        arr=[[]*n]*n
        for i in range(n):
            arr[i] = list(map(int, input().split()))
        print(btfl(arr))
