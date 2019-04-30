class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        dsu = DSU()
        for edge in edges:
            if not dsu.union(*edge):
                return edge

class DSU(object):

    """Union find data structure"""

    def __init__(self):
        """init: initialize parents and their rank. """
        self.par = range(1001)
        self.rnk = [0] * 1001

    def find(self, x):
        """Docstring for find.
        Keep moving current node up until hit parent
        :returns: a node that is the root

        """
        # if not parent, keep movin' up

        # Naive approach:
        # while x != self.par[x]:
        #     x = self.par[x]
        # return x
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]

    def union(self, x, y):
        """Docstring for union.
        :x: node x
        :y: node y
        :returns: TODO

        """
        xr, yr = self.find(x), self.find(y)
        if xr == yr:
            return False
        elif self.rnk[xr] < self.rnk[yr]:
            self.par[xr] = yr
        elif self.rnk[yr] < self.rnk[xr]:
            self.par[yr] = xr
        else:
            self.par[yr] = xr
            self.rnk[xr] += 1
        return True
