def prsionbreak(l:list)->int:
    count=0
    for i in range(len(l)):
        if l[i]==1:
            count+=1
            n=count
            if i<len(l)-1:
                if n%2==1:
                    if l[i+1]==1:
                        l[i+1]=0
                    else:
                        l[i+1]=1
        else:
            if i<len(l)-1:
                if n%2==1:
                    if l[i+1]==1:
                        l[i+1]=0
                    else:
                        l[i+1]=1
                
    return count

print(prsionbreak([1,1,1]))
print(prsionbreak([1,1,0,0,0,1,0]))
print(prsionbreak([1,0]))
print(prsionbreak([1,0,0]))

# """ 
# [1,0,0,0,1,1,0]
#  ^ 1 1 1 0 0 1
#    ^ 0 0 1 1 0
#          ^
# """"
print(prsionbreak([1,0,0,0,0,0,0]))
print(prsionbreak([1,1,1,0,0,0]))
print(prsionbreak([1,0,1,0,1,0]))