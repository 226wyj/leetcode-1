#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 advpetc <chenhaoy@usc.edu>
#
# Distributed under terms of the MIT license.

"""
Description
Given an array of integers, find how many pairs in the array such that their sum is less than or equal to a specific target number. Please return the number of pairs.



Example
Given nums = [2, 7, 11, 15], target = 24.
Return 5.
2 + 7 < 24
2 + 11 < 24
2 + 15 < 24
7 + 11 < 24
7 + 15 < 25
"""

def solution(nums, target):
    if len(nums) < 2: return 0
    nums.sort()
    left, right, count = 0, len(nums) - 1, 0
    while left < right:
        if nums[left] + nums[right] <= target:
            count += (right - left)
            left += 1
        else:
            right -= 1
    return count

print(solution([2, 7, 11, 15], 24))


"""
    Given an array nums of n integers, find two integers in nums such that the sum is closest to a given number, target.

    Return the difference between the sum of the two integers and the target.

    Example: Given array nums = [-1, 2, 1, -4], and target = 4.

    The minimum difference is 1. (4 - (2 + 1) = 1).

    Do it in O(nlogn) time complexity.
"""
def two_sum_closest(nums, target):
    if len(nums) < 2: return ()
    nums.sort()
    left, right, diff = 0, len(nums) - 1, float("inf")
    while left < right:
        s = nums[left] + nums[right]
        if s > target:
            right -= 1
        else:
            left += 1
        diff = min(diff, abs(s - target))
    return diff

def two_sum_closest_v2(ar1, ar2, target):
    """ given two array, find closest to target """
    diff = float("inf")
    m, n = len(ar1), len(ar2)
    l, r = 0, n - 1 

    while (l < m and r >= 0):
        if abs(ar1[l] + ar2[r] - target) < diff:
            res_l = l
            res_r = r
            diff = abs(ar1[l] + ar2[r] - target)
        if ar1[l] + ar2[r] > target:
            r -= 1
        else:
            l += 1
    return ar1[res_l], ar2[res_r]

print(two_sum_closest([-1, 2, 1, -4], 4))
print(two_sum_closest_v2([1, 4, 5, 7], [10, 20, 30, 40], 38))

"""
two sum: if there are two pairs, return the one with the larger value
"""

# def two_sum(nums, target):
#     if len(nums) < 2: return ()
#     nums.sort()
#     m = {}
#     for n : nums:
#         if (target - n) in nums:


