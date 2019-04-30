#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 advpetc <chenhaoy@usc.edu>
#
# Distributed under terms of the MIT license.

"""
城市建路题。题目意思是有一定数量的城市，城市之间已经有了一些道路。还有一些可以供选择的道路来建设。每个新建的道路有 cost。问如果要连接所有的城市，新建路的最小的 cost 是多少。举个栗子：
Input 如下：
numTotalAvailableCities = 6
numTotalAvailableRoads = 3
roadsAvailable = [[1, 4], [4, 5], [2, 3]]
numNewRoadsConstruct = 4
costNewRoadsConstruct = [[1, 2, 5], [1, 3, 10], [1, 6, 2], [5, 6, 5]]
Output 应该是： 7
解释：numTotalAvailableCities = 6 意思是城市的编号从 1 到 6。基于提供的 roadsAvailable list, 这 6 个城市中 已经形成了三个岛， 分别为 [1, 4, 5], [2, 3] 和 [6]。 现在要从 costNewRoadsConstruct list 中选一些路来建使得所有的城市都被连接。这个例子中，显然要选择[1, 2, 5] 和 [1, 6, 2] 这两条路。总的 cost 就是 5 + 2 = 7。

解题思路：
这是个最小生成树（MST）问题。但要注意整个图中已经有一些边了，不是从0开始的最小生成树。具体来说，可以先Union-Find所有已经有的路 in roadsAvailable list，然后把所有可以建的路 in costNewRoadsConstruct list 按照 cost 排序放入 min-heap。然后每次从 min-heap 中拿出最小 cost 的路来接着 Union-Find整个图。每次需要Union的时候，累积目前为止的 cost。当总的 edges 数目等于总的 vertices 数目减 1 时，整个图就被构建成了一颗树。这时输入累积的cost作为输出。
注意：
这个题不太容易过所有的 test case （目前有19个test cases），因为有些坑需要避免。
1. 城市的ID是从1开始，不是从0开始。所以UnionFind的时候要多注意。
2. 输入的roadsAvailable list 和 costNewRoadsConstruct list 互相之间可能有重复。所以不要在算Graph中的 edges 数目的时候要格外注意。
"""

def solve(numTotalAvailableCities,
        numTotalAvailableRoads,
        roadsAvailable,
        numNewRoadsConstruct,
        costNewRoadsConstruct):
    """TODO: Docstring for solve.
    :returns: TODO

    """
    if numTotalAvailableCities < 2 or numTotalAvailableRoads >= numTotalAvailableCities - 1:
        return 0
    uf = UnionFind(numTotalAvailableCities)
    existing = 0
    for (city1, city2) in roadsAvailable:
        if not uf.find(city1, city2):
            uf.union(city1, city2)
            existing += 1
    import heapq
    h = []
    for (city1, city2, cost) in costNewRoadsConstruct:
        heapq.heappush(h, (cost, city1, city2))
    mst = list()
    while h and len(mst) + existing < numTotalAvailableCities - 1:
        cost, city1, city2 = heapq.heappop(h)
        if not uf.find(city1, city2):
            uf.union(city1, city2)
            mst.append(cost)

    if len(mst) + existing < numTotalAvailableCities - 1:
        return -1

    print(sum(mst))

class UnionFind(object):

    """Docstring for UnionFind. """

    def __init__(self, size):
        """TODO: to be defined1. """
        self.ids = list()
        for i in range(size + 1):
            self.ids.append(i)
    def root(self, i):
        """TODO: Docstring for root.
        :returns: TODO

        """
        while self.ids[i] != i:
            i = self.ids[i]
        return i
    def find(self, i, j):
        """TODO: Docstring for find.
        :returns: TODO

        """
        return self.root(i) == self.root(j)
    def union(self, i, j):
        """TODO: Docstring for union.
        :returns: TODO

        """
        rooti = self.root(i)
        rootj = self.root(j)
        self.ids[rooti] = rootj


solve(
        numTotalAvailableCities = 6,
        numTotalAvailableRoads = 3,
        roadsAvailable = [[1, 4], [4, 5], [2, 3]],
        numNewRoadsConstruct = 4,
        costNewRoadsConstruct = [[1, 2, 5], [1, 3, 10], [1, 6, 2], [5, 6, 5]]
        )
