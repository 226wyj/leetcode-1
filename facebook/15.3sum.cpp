class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        if (nums.size() < 3)
            return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int curr = nums[i];
            if (i > 0 && curr == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = curr + nums[left] + nums[right];
                if (sum == 0) {
                    res.push_back({ curr, nums[left], nums[right] });
                    left++, right--;
                    // comparing with the current one with the next one, where
                    // the current one is actually the previous one
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (right > left && nums[right] == nums[right + 1])
                        right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};
