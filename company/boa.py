#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 Haoyang <peter@peterchen.xyz>
#
# Distributed under terms of the MIT license.

"""
Given an unsorted array, find and return target sum in increasing order
"""


def solution(arr, target):
    s = set()
    res = []
    for e in arr:
        _e = int(e)
        if _e not in s and (target - _e) in s:
            res.append([_e, target - _e])
        s.add(_e)
    sorted(res, key=lambda a: a[0])
    return res


str = "1,3,7,2,3,4,8;10"
arr = str[0:str.find(';')].split(',')
target = int(str[str.find(';') + 1:])
print(solution(arr, target))


"""
Programming challenge description:
You are given a number N and a pattern. The pattern consists of lowercase latin letters and one operation "+" or "-". The challenge is to split the number and evaluate it according to this pattern e.g.
1232 ab+cd -> a:1, b:2, c:3, d:2 -> 12+32 -> 44
Input:
Your program should read lines from standard input. Each line contains the number and the pattern separated by a single whitespace. The number will be in range [100, 1000000000]. All test cases contain valid expressions (no leading zeros).
Output:
Print out the result of the pattern evaluation.
"""



def pattern_match(str, pattern):

    op = True  # default to plus
    idx = 0
    for i, s in enumerate(pattern):
        if s == '+':
            op = True
            idx = i
            break
        elif s == '-':
            op = False
            idx = i
            break
    if op:
        return int(str[0:idx]) + int(str[idx:])
    else:
        return int(str[0:idx]) - int(str[idx:])

import sys
for line in sys.stdin:
    str = line.split()[0]
    pattern = line.split()[1]
    print(pattern_match(str, pattern))

# print(pattern_match("3413289830", "a-bcdefghij"))
# print(pattern_match("776", "a+bc"))
