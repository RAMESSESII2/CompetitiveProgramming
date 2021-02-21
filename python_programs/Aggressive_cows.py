def binary_search(position, n, c) -> int:
    def condition(position, value, c) -> bool:
        return check(position, value, c)
    left, right =0, position[len(position)-1]-position[0]
    ans=-1  # could be [0, n], [1, n] etc. Depends on problem
    while left <= right:
        mid = left + (right - left) // 2
        if condition(position, mid, c):
            ans=mid
            left = mid + 1
        else:
            right = mid - 1
    return ans

def check(position, diff, c):
    count=1
    lposition=position[0]
    for i in range(1, len(position)):
        if position[i] - lposition >= diff:
            count+=1
            lposition=position[i]
        if count==c:
            return True
    return False

if __name__=='__main__':
    for i in range(int(input())):
        n, c = map(int, input().split())
        position=[]
        for i in range(n):
            position.append(int(input()))
        position.sort()
        print(binary_search(position, n, c))