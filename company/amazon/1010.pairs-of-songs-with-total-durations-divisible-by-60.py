class Solution(object):
    def numPairsDivisibleBy60(self, time):
        """
        :type time: List[int]
        :rtype: int
        """
        # store the reminder of each time to c
        c = collections.Counter()
        res = 0
        # 1, 2, 59, 60
        # (60 - 1 % 60) % 60 = 59
        # (60 - 2 % 60) % 60 = 58
        # (60 - 59 % 60) % 60 = 1 
        # (60 - 60 % 60) % 60 = 0 

        for t in time:
            res += c[(60 - t % 60) % 60]
            c[t % 60] += 1
        return res
