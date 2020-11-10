/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
  string decodeString(string s) {
    stack<int> times;
    stack<string> stk;
    int cnt = 0;
    string t = "";
    for (char c : s) {
      if (c <= '9' && c >= '0') {
        cnt = cnt * 10 + c - '0';
      } else if (c == '[') {
        times.push(cnt);
        stk.push(t);
        cnt = 0;
        t = "";
      } else if (c == ']') {
        int time = times.top();
        times.pop();
        for (int i = 0; i < time; ++i) {
          stk.top() += t;
        }
        t = stk.top();
        stk.pop();
      } else {
        t += c;
      }
    }
    return stk.empty() ? t : stk.top();
  }
};
// @lc code=end
