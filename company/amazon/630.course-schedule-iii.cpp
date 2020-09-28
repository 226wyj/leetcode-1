/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

// @lc code=start
class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    sort(courses.begin(), courses.end(),
         [](vector<int> &l, vector<int> &r) { return l[1] < r[1]; });
    priority_queue<int> lastFinish;
    int total_time = 0;
    for (auto c : courses) {
      lastFinish.push(c[0]);
      total_time += c[0];
      if (c[1] < total_time) { // can finish before total_time
        total_time -= lastFinish.top();
        lastFinish.pop();
      }
    }
    return lastFinish.size();
  }
};
// @lc code=end
