def intreverse(n):
    s=0
    while(n>0):
        r=(n%10)
        s=s*10+r
        n=int(n//10)
    return(s)

def matched(s):
    c=d=0
    for i in range(0,len(s)):
        if(s[i]=='('):
            c+=1
        if(s[i]==')'):
            d+=1
    if(c==d):
        return(True)
    else:
        return(False)

def prime(x):
    if(x==0 or x==1):
        return(False)
    else:
        e=0
        for i in range(1,(x/2)+1):
            if((x%i)==0):
                e+=1
    if(e==1):
            return(True)
        

def sumprimes(l):
    s=0
    for i in range(0,len(l)):
        if (prime(l[i])==True):
            s=s+l[i]
    return(s)
        
        
