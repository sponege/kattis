import sys
i=[int(a) for a in sys.stdin.read()[:-1]]
print(i)
swaps=0
def mergesort(arr_to_sort):
    global swaps
    """Recursively splits and merges an unsorted list to a sorted list."""

    if len(arr_to_sort) == 1:
        return arr_to_sort

    left = mergesort(arr_to_sort[len(arr_to_sort)//2:])
    right = mergesort(arr_to_sort[:len(arr_to_sort)//2])

    merged_list = []

    while len(left) > 0 and len(right) > 0:
        swaps+=1
        if left[0] < right[0]:
            merged_list.append(left[0])
            left = left[1:]
        else:
            merged_list.append(right[0])
            right = right[1:]

    left += right
    merged_list += left

    return merged_list
a=mergesort(i)
print(a)
print(swaps)
