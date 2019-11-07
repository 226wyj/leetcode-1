#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 Haoyang <peter@peterchen.xyz>
#
# Distributed under terms of the MIT license.

"""
array A is greater than array B when
the first non-matching element in two array
that A[i] is greater than B[i]

Given one array T, and a value K (k < len(T))
find all subarray, and return the greatest one
"""


def largest_arr(A, K):
    start = 0
    for i in range(1, len(A) - K + 1):
        if A[start] < A[i]:
            start = i
    return A[start:start + K]


print(largest_arr([1, 4, 3, 2, 5], 2))
