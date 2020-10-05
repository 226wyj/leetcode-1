/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
  int rob(vector<int> &nums, int l, int r) {
    int rob = 0, notRob = 0;

    for (int i = l; i < r; ++i) {
      int preRob = rob, preNotRob = notRob;
      rob = preNotRob + nums[i];
      notRob = max(preRob, preNotRob);
    }
    return max(rob, notRob);
  }
  int rob(vector<int> &nums) {
    if (nums.size() <= 1)
      return nums.empty() ? 0 : nums[0];
    return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
  }
};
// @lc code=end
