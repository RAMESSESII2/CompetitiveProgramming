def merge(array, l, mid, r):
    count=0
    temp=[0]*(r-l+1)
    i=l
    j=mid
    k=0
    while(i<mid and j<=r ):
        if(array[i]<=array[j]):
            temp[k]=array[i]
            i+=1
            k+=1
        else:
            temp[k]=array[j]
            k+=1
            j+=1
            count+=mid-i
    while(i<mid):
        temp[k]=array[i]
        i+=1
        k+=1
    while(j<=r):
        temp[k]=array[j]
        k+=1
        j+=1
    k=0
    for i in range(l, r+1):
        array[i]=temp[k]
        k+=1
    return count

def merge_sort(array ,l , r):
    count=0
    while(l<r):
        mid=(r+l)//2
        ansleft=merge_sort(array, l, mid)
        ansright=merge_sort(array, mid+1, r)
        ans=merge(array, l, mid+1, r)
        return (ans+ansleft+ansright)
    return count
""" if __name__=='__main__':
    for i in range(int(input())):
        print("\n")
        position=[]
        position.append(int(input()))
        for i in range(position[0]):
            position.append(int(input()))
        n=len(position)
        print(merge_sort(position, 0, n-1)) """
print(merge_sort([5,4,2,3,1], 0, 4))


