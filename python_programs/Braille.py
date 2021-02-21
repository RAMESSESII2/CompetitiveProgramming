from time import time
start_time = time()

def solution(s):
    if len(s)==0:
        return s
    if len(s)>=50:
        s=s[:49]
    brailmaps={
        "a":"100000",
        "b":"110000",
        "d":"100110",
        "e":"100010",
        "c":"100100",
        "f":"110100",
        "g":"110110",
        "h":"110010",
        "i":"010100",
        "j":"010110",
        "k":"101000",
        "l":"111000",
        "m":"101100",
        "n":"101110",
        "o":"101010",
        "p":"111100",
        "q":"111110",
        "r":"111010",
        "s":"011100",
        "t":"011110",
        "u":"101001",
        "v":"111001",
        "w":"010111",
        "x":"101101",
        "y":"101111",
        "z":"101011",
        "Caps":"000001",
        "blank":"000000"
    }
    l=s.split()
    string=""
    if len(l)==0:
        for i in s:
             string+=(brailmaps["blank"])
        return string
    m=0
    if s[0]==" ":
        string+=(brailmaps["blank"])    
    for k in range(len(l)):
        if len(l[k])==1:
            if l[k] in brailmaps.keys():
                    string+=(brailmaps[l[k]])
            else:
                string+=(brailmaps["Caps"])
                string+=(brailmaps[chr(ord(l[k])+32)])
        elif len(l[k])>1 and ord(l[k][1])<91:
            string+=(brailmaps["Caps"])
            string+=(brailmaps["Caps"])
            for j in l[k]:
                string+=(brailmaps[chr(ord(j)+32)])
        else:
            for i,v in enumerate(l[k]):
                if v in brailmaps.keys():
                    string+=(brailmaps[v])
                else:
                    string+=(brailmaps["Caps"])
                    string+=(brailmaps[chr(ord(v)+32)])
        if(m!=len(l)-1):
            string+=(brailmaps["blank"])
        m+=1     
    if len(s)>1 and s[len(s)-1]==" ":
        string+=(brailmaps["blank"])
    return string
        
print(solution("Code ME IN"))
print(solution("BIG"))
print(solution("hand me over RIGHT"))
print(solution("a"))
print(solution("The quick brown fox jumps over the lazy dog"))
print(solution(" What a moment a "))
print(solution("     "))
print(solution(" akfhakhvhjvskgrggwegkhbvhbhjvgygahvgfgfsgfgsfsbfwiyiuyeiweiytwvebvwbevghcwgecgweghvwgevweuwe "))

passed_time = time() - start_time
print(f"It took {passed_time}")