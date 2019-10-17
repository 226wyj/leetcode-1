class Solution {
public:
    vector<vector<int>> dirs{ { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
    int numDistinctIslands(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        unordered_set<string> res;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    set<string> s;
                    helper(grid, i, j, i, j, visited, s);
                    string t = "";
                    for (auto str : s) {
                        t += str + "_";
                        res.insert(t);
                    }
                }
            }
        }
        return res.size();
    }

    /******************************************************************************
     * Function:         void helper
     * Description:
     * Where:
     *                   vector<vector<int>>& grid - TODO
     *                   int x0 - TODO
     *                   int y0 - TODO
     *                   int i - TODO
     *                   int j - TODO
     *                    - TODO
     * Return:
     * Error:
     *****************************************************************************/
    void helper(vector<vector<int>>& grid, int x0, int y0, int i, int j,
        vector<vector<bool>>& visited, set<string>& s)
    {
        int m = grid.size(), n = grid[0].size();
        visited[i][j] = true;
        for (auto dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0
                || visited[x][y])
                continue;
            string str = to_string(x - x0) + "_" + to_string(y - y0);
            s.insert(str);
            helper(grid, x0, y0, x, y, visited, s);
        }
    }
};
