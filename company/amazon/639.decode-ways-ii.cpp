/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 */

// @lc code=start
class Solution {
public:
  int numDecodings(string s) {
    int n = s.size(), M = 1e9 + 7;
    vector<long> dp(n + 1, 0);
    dp[0] = 1;
    if (s[0] == '0')
      return 0;
    dp[1] = (s[0] == '*') ? 9 : 1;
    for (int i = 2; i <= n; ++i) {
      if (s[i - 1] == '0') {
        if (s[i - 2] == '1' ||
            s[i - 2] == '2') { // 110: -> 110, 120: -> 120 no change
          dp[i] += dp[i - 2];
        } else if (s[i - 2] == '*') { // 1*0: 110 or 120
          dp[i] += 2 * dp[i - 2];
        } else { // 100: not possible
          return 0;
        }
      } else if (s[i - 1] >= '1' && s[i - 1] <= '9') {
        dp[i] += dp[i - 1]; // itself can be a char
        if (s[i - 2] == '1' ||
            (s[i - 2] == '2' && s[i - 1] <= '6')) { // 10-19 and 20-26
          dp[i] += dp[i - 2];
        } else if (s[i - 2] ==
                   '*') { // 1*X: if X <= 6 then * can choose either 1 or 2, so
                          // double the size; 1*X: if X > 6: then * cannot make
                          // a word together with X
          dp[i] += (s[i - 1] <= '6') ? (2 * dp[i - 2]) : dp[i - 2];
        }
      } else { // s[i - 1] == '*'
        dp[i] += 9 * dp[i - 1]; // 11, 12....19
        if (s[i - 2] == '1')
          dp[i] += 9 * dp[i - 2];
        else if (s[i - 2] == '2')
          dp[i] += 6 * dp[i - 2];
        else if (s[i - 2] == '*')
          dp[i] += 15 * dp[i - 2];
      }
      dp[i] %= M;
    }
    return dp[n];
  }
};
// @lc code=end
