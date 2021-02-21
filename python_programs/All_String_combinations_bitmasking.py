ix,xport time
start_time = time.time()
from collections import deque

#class CombinationIterator:
def init(characters: str, combinationLength: int):
    n = len(characters)
    list = deque()

    def recurse(mask, i, current):
        if combinationLength == len(current):
            list.append(current)
            return
        for j in range(i, n):
            if (mask & (1 << j)) > 0:
                recurse(mask ^ (1 << j), j + 1, current + characters[j])
    recurse((1 << n) - 1, 0, "")
    return list

def next(list) -> str:
    return list.popleft()

def hasNext(list) -> bool:
    return len(list) > 0

print(init("abcd",2))
print(init("abcdefghi", 5))
print(init("abcdefghi", 2))
print(init("abcdefghi", 1))
print(init("abcdefghi", 3))
# def next(string, let):
#     dic={}
#     diff = len(string) - let
#     l=[]
#     if let==1:
#         for x in string:
#             l.append(x)
#         return l

#     elif diff>0:
#         for i in range(len(string)-diff+2):
#             for j in range(i,len(string)):
#                 if j>=i+let-1 and string[i:i+let-1]+string[j] not in [*dic]:
#                     dic[string[i:i + let - 1] + string[j]] = 1
#         return [*dic]

#     else:
#         return False

# print(next("ahijp", 2))
# print(next("abcdefg", 3))
# print(next("abcd", 2))
# print(next("abcdefghi", 5))
# print(
#     next("gkosu", 3))

end_time = time.time()
# Time taken in seconds
time_taken = end_time - start_time
print(time_taken)
