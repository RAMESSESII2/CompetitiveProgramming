import sys
import random as rnd

sys.stdout = open("out.txt", "w")
sys.stdin = open("in.txt", "r")
def solver(arr, I, r):
    if r <= 0:
        return -1
    random_ind = int(rnd.randrange(47589234)) % (r)
    random_ele = arr[random_ind]
    # print(random_ind, random_ele, I, r, arr)
    left = []
    right = []
    for i in range(r):
        if arr[i] < random_ele:
            left.append(arr[i])
        if arr[i] > random_ele:
            right.append(arr[i])
    p = len(left) + 1
    # print(p)
    if p == I:
        return random_ele
    if p < I and right:
        # print(right)
        # arr = right
        return solver(right, I - p, r - p)
    if p > I and left:
        # print(left)
        # arr = left
        return solver(left, I, p - 1)


if __name__ == "__main__":
    # for i in range(int(input())):
    N = int(input())
    I = int(input())
    # pc pr = map(int input().split())
    arr = list(map(int, input().split()))
    print(solver(arr, I, N))

# import random
# def kthSmallest(arr, l, r, k):
#     # If k is smaller than number of
#     # elements in array
#     if k > 0 and k <= r - l + 1:

#         # Partition the array around a random
#         # element and get position of pivot
#         # element in sorted array
#         pos = randomPartition(arr, l, r)

#         # If position is same as k
#         if pos - l == k - 1:
#             return arr[pos]
#         if pos - l > k - 1:  # If position is more,
#             # recur for left subarray
#             return kthSmallest(arr, l, pos - 1, k)

#         # Else recur for right subarray
#         return kthSmallest(arr, pos + 1, r, k - pos + l - 1)

#     # If k is more than the number of
#     # elements in the array
#     return 999999999999


# def swap(arr, a, b):
#     temp = arr[a]
#     arr[a] = arr[b]
#     arr[b] = temp


# # Standard partition process of QuickSort().
# # It considers the last element as pivot and
# # moves all smaller element to left of it and
# # greater elements to right. This function
# # is used by randomPartition()
# def partition(arr, l, r):
#     x = arr[r]
#     i = l
#     for j in range(l, r):
#         if arr[j] <= x:
#             swap(arr, i, j)
#             i += 1
#     swap(arr, i, r)
#     return i


# # Picks a random pivot element between l and r
# # and partitions arr[l..r] around the randomly
# # picked element using partition()
# def randomPartition(arr, l, r):
#     n = r - l + 1
#     pivot = int(random.random() % n)
#     swap(arr, l + pivot, r)
#     return partition(arr, l, r)


# # if __name__ == "__main__":
# #     arr = [12, 3, 5, 7, 4, 19, 26]
#     n = len(arr)
#     k = 3
#     print("K'th smallest element is", kthSmallest(arr, 0, n - 1, k))
# """
# find a random element and put that int
# """


