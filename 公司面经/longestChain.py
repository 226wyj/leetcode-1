#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 Haoyang <peter@peterchen.xyz>
#
# Distributed under terms of the MIT license.

"""
{"a", "b", "ba", "bca", "bda", "bdca"}
  0    0    2     
"""


def longestChain(str):
    dp = {}
    res = 0
    for s in sorted(str):
        dp[s] = max(dp.get(s[:i] + s[i + 1:], 0) + 1 for i in range(len(s)))
        res = max(res, dp[s])
    print(dp)
    return res


print(longestChain(["a", "and", "an", "bear"]))
