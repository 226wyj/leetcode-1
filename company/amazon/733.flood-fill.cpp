/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
  int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  void dfs(int x, int y, int org, int color, vector<vector<int>> &g) {
    if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] != org || g[x][y] == color)
      return;
    g[x][y] = color;
    for (auto d : dir) {
      dfs(x + d[0], y + d[1], org, color, g);
    }
  }
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    dfs(sr, sc, image[sr][sc], newColor, image);
    return image;
  }
};
// @lc code=end

/*
2 2 2
2 2 0
2 0 1
   */
