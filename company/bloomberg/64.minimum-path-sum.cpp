/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (!i && j)
          grid[i][j] = grid[i][j] + grid[i][j - 1];
        else if (i && !j)
          grid[i][j] = grid[i - 1][j] + grid[i][j];
        else if (!i && !j)
          continue;
        else
          grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
      }
    }
    return grid.back().back();
  }
};
// @lc code=end
