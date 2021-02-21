def longpad(string:str):
    if len(string)==0 or len(string)==1:
        return string
    li=0
    fi=1
    re1=0
    re2=1
    longest=1
    for i in range(1,len(string)):
        left=i-1
        right=i
        while left>=0 and right<len(string):
            if string[left]!=string[right]:
                break
            left-=1
            right+=1
        li=left+1
        fi=right
        if fi-li>longest:
            longest=fi-li
            re1=right
            re2=left+1
        left=i-1
        right=i+1
        while left>=0 and right<len(string):
            if string[left]!=string[right]:
                break
            left-=1
            right+=1 
        li=left+1
        fi=right
        if fi-li>longest:
            longest=fi-li
            re1=right
            re2=left+1
    return string[re2:re1]
print(longpad("a"))  