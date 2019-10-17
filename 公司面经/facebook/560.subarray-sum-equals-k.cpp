class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int n = (int)nums.size();
        // key: sum from 0 to i, value: # of this sum occurred
        unordered_map<int, int> m;
        int res = 0;
        int curr_sum = 0;
        m[0] = 1; // there is always a way to form sum of 0
        for (int i = 0; i < n; ++i) {
            curr_sum += nums[i];
            res += m[curr_sum - k];
            m[curr_sum]++;
        }
        return res;
    }
};
