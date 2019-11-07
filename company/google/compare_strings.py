#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 Haoyang <peter@peterchen.xyz>
#
# Distributed under terms of the MIT license.

"""
One string is strictly smaller than another when
the frequency of occurence of the smallest character
in the string is less than the frequency of occurence
of the smallest character in the comparison string.

A = 'abcd aabc bd' B = 'aaa aa'
abcd: a -> 1       aaa: a -> 3
aabc: a -> 2       aa: a -> 2
bd: b -> 1

1 < 3, 2 < 3, 1 < 3 -> 3
1 < 2, 2 = 2, 1 < 2 -> 2
"""


def comparison(A, B):
    def getFreq(s):
        checker = [0 for _ in range(26)]
        for c in s:
            checker[ord(c) - 97] += 1
        for c in checker:
            if c != 0:
                print(c)
                return c
        return 0
    s_a, s_b = A.split(','), B.split(',')
    bucket = [0 for _ in range(11)]
    for s in s_a:
        bucket[getFreq(s)] += 1
    for i in range(1, len(bucket)):
        bucket[i] = bucket[i - 1] + bucket[i]

    res = []
    for s in s_b:
        res.append(bucket[getFreq(s) - 1])
    print(res)


comparison('abcd,aabc,bd', 'aaa,aa')
