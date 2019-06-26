class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int currSum = nums[0], res = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            currSum = max(nums[i], currSum + nums[i]);
            res = max(res, currSum);
        }
        return res;
    }
};
