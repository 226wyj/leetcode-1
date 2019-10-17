class Solution {
public:
    int numFriendRequests(vector<int>& ages)
    {
        int res = 0;
        vector<int> numInAge(121), sumInAge(121);
        for (int age : ages) {
            ++numInAge[age];
        }
        // 记录每一个小于等于当前index年龄的人数
        for (int i = 1; i <= 120; ++i) {
            sumInAge[i] = numInAge[i] + sumInAge[i - 1];
        }
        // 需要大于14岁，所以从15开始
        for (int i = 15; i <= 120; ++i) {
            if (numInAge[i] == 0)
                continue;
            // 比当前的年龄大的
            int cnt = sumInAge[i] - sumInAge[i * 0.5 + 7];
            res += cnt * numInAge[i] - numInAge[i];
        }
        return res;
    }
};
