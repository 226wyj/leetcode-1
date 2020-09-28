/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    stack<int> idx; // store current greater's index
    map<int, int> mp;
    for (int i = 0; i < nums2.size(); ++i) {
      while (!idx.empty() && nums2[idx.top()] < nums2[i]) {
        mp[nums2[idx.top()]] = nums2[i];
        idx.pop();
      }
      idx.push(i);
    }
    while (!idx.empty()) {
      mp[nums2[idx.top()]] = -1;
      idx.pop();
    }
    vector<int> res(nums1.size());
    for (int i = 0; i < nums1.size(); ++i) {
      res[i] = mp[nums1[i]];
    }
    return res;
  }
};
// @lc code=end
