"""
https://leetcode.com/discuss/interview-question/396646/
"""
def rob(arr, num):
    f = g = [[False] * (num + 1)] * (len(arr) + 1)
    for i in range(len(arr) + 1):
        f[i][0] = g[i][0] = True
    for i in range(1, len(arr)):
        for j in range(1, num):
            if j >= arr[i - 1] and g[i - 1][j - arr[i - 1]]:
                g[i][j] = True
            g[i][j] = g[i - 1][j] or f[i - 1][j]

    for i in reversed(range(0, len(arr) - 1)):
        for j in reversed(range(0, num - 1)):
            if f[i][j] or g[i][j]:
                return j
    return -1

print(rob([10, 20, 30, 40, 50, 900], 100)) # output 90
