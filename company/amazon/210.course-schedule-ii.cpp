/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> degree(numCourses);
    map<int, vector<int>> g;
    for (auto p : prerequisites) {
      g[p[1]].push_back(p[0]);
      degree[p[0]]++;
    }
    queue<int> q;
    vector<int> res;
    for (int i = 0; i < numCourses; ++i)
      if (degree[i] == 0)
        q.push(i);
    while (!q.empty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        res.push_back(q.front());
        for (int c : g[q.front()])
          if (--degree[c] == 0)
            q.push(c);
        q.pop();
      }
    }
    for (int d : degree)
      if (d != 0)
        return {};
    return res;
  }
};
// @lc code=end
