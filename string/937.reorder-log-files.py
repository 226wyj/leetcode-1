class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        def f(log):
            # split each log string with id and the rest
            # for example "a1 9 2 3 1"
            # id -> "a1", rest = "9 2 3 1"
            id_, rest = log.split(" ", 1)
            # if rest[0] is a english character, then make it the
            # highest order
            # if want the rest number is in ascending order, then
            # need to do:
            # return (0, rest, id_) if rest[0].isalpha() else (1, rest, id_)
            return (0, rest, id_) if rest[0].isalpha() else (1,)
        return sorted(logs, key=f)

sol = Solution()
res = sol.reorderLogFiles(["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"])
print(res)
