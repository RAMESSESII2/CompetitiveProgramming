def anagram(S,P):
    sortdS = ("").join(sorted(S))
    sortdP = ("").join(sorted(A))
    store={}
    for i,pat in enumerate(sortdP):
        for j,val in enumerate(sortdA):
            if val==pat:
                store[pat]=j


    return




if __name__=='__main__':
    T = int(input())
    for i in range(T):
        S=input()
        P=input()
        print(anagram(S,P))