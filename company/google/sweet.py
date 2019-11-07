#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 Haoyang <peter@peterchen.xyz>
#
# Distributed under terms of the MIT license.

"""

"""
def calculate(str):
    res = []
    def dfs(str, path, visited):
        if len(path) == len(str):
            res.append(path)
            return
        for i in range(0, len(str)):
            if str[i] in visited:
                continue
            else:
                visited.add(str[i])
            path += str[i]
            dfs(str, path, visited)
            path = path[:-1]
            visited.remove(str[i])
    s = set()
    dfs(str, "", s)
    return res
print(len(calculate('abcd')))
