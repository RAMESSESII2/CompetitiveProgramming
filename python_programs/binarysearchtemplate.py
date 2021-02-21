def binary_search(array) -> int:
    def condition(value) -> bool:
        pass
    left, right = min(search_space), max(
        search_space)  # could be [0, n], [1, n] etc. Depends on problem
    while left < right:
        mid = left + (right - left) // 2
        if condition(mid):
            right = mid
        else:
            left = mid + 1
    return lef


# def binary_search(array, search) -> int:
#     def condition(value,search) -> bool:
#         return search<array[value]
#     left, right = 0, len(array)-1  # could be [0, n],[1, n] etc. Depends on problem
#     while left < right:
#         mid = left + (right - left) // 2
#         if array[mid]==search:
#             return mid+1
#         elif condition(mid, search):
#             right = mid
#         else:
#             left = mid + 1
#     return -1

