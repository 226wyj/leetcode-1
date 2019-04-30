#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 advpetc <chenhaoy@usc.edu>
#
# Distributed under terms of the MIT license.

"""
第一题：零件组装题。题目意思就是有一堆零件，每个零件的尺寸和组装需要的时间是一样的。输入各个零件的尺寸的list，要求输出最短的总的 accumulated 组装时间。这么说估计也很难描述清楚，直接上例子：
比如输入的list是 {8， 4， 6， 12}。
1. 先选 4 和 6组装到一起，形成 size 为 10 的新零件。目前为止耗时为10。零件的 list 变为 {8， 10， 12}
2. 再选 8 和 10 组装到一起，形成 size 为 18 的新零件。目前为止耗时为 10 + 18 = 28。零件的 list 变为 {12， 18}
3. 最后 把 12 和 18 组装到一起，形成 size 为 30 的新零件。目前为止耗时为 10 + 18 + 30 = 58。
最后输出 58 就可以了。
"""
import heapq

def solve(data):
    """TODO: Docstring for solve.
    :returns: TODO

    """
    if not data:
        print(0)
        return
    heapq.heapify(data)
    cost = 0
    while len(data) >= 2:
        first = heapq.heappop(data)
        second = heapq.heappop(data)
        cost += (first + second)
        heapq.heappush(data, first + second)
    print(cost)

solve([8, 4, 6, 12])
