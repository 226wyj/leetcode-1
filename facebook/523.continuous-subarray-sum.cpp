class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        int sum = 0;
        unordered_map<int, int> m{ { { 0, -1 } } };
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (k != 0) {
                sum %= k; // store the reminder
            }
            if (m.count(sum)) {
                // i and previous reminder isn't in the same index
                if (i - m[sum] > 1)
                    return true;
            } else {
                m[sum] = i;
            }
        }
        return false;
    }
};
