class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0)
            return {};
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = 0 - nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    res.push_back({ nums[i], nums[left], nums[right] });
                    // duplicate
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    // duplicate
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    ++left;
                    --right;
                } else if (nums[left] + nums[right] < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return res;
    }
};
