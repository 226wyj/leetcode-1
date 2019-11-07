"""
https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/discuss/119835/Java-O(n)-DP-Solution
"""

def minSwap(A, B):
    # if any two are all in decreasing order, then there is no way to swap
    for i in range(1, len(A)):
        if A[i] < A[i - 1] and B[i] < B[i - 1]:
            return -1
    swap, noSwap = 1, 0
    for i in range(1, len(A)):
        if A[i - 1] >= B[i] or B[i - 1] >= A[i]:
            swap += 1 # have to swap the next one if swap the current one
        elif A[i - 1] >= A[i] or B[i - 1] >= B[i]:
            tmp = swap
            swap = noSwap + 1
            noSwap = tmp
        else:
            swap, noSwap = min(swap, noSwap) + 1, min(swap, noSwap)
    return min(swap, noSwap)

print(minSwap([4, 1], [3, 2]))
