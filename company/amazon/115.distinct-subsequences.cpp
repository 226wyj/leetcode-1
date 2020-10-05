/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
  int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    // dp[i][j]: # of matches between s[0-i] and s[0-j]
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (j == 0) // t is "", this elminate the case when s = "", t = ""
          dp[i][j] = 1;
        else if (i == 0) // s is ""
          dp[i][j] = 0;
        else if (s[i] == t[j]) // with t[j] and w/o t[j]
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp.back().back();
  }
};
// @lc code=end
