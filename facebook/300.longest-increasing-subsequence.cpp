class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> dp;
        for (int n : nums) {
            int left = 0, right = dp.size();
            while (left < right) {
                int mid = (left + right) >> 1;
                if (dp[mid] < n)
                    left = mid + 1;
                else
                    right = mid;
            }
            if (right >= dp.size())
                dp.push_back(n);
            else
                dp[right] = n;
        }
        return dp.size();
    }
};
