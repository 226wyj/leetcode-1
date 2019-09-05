class Solution {
public:
    int sz;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n)
    {
        unordered_set<int> xy_diff, xy_sum;
        set<int> queens;
        // unordered_set<pair<int, int>> queens;
        sz = n;
        dfs(queens, xy_diff, xy_sum);
        return res;
    }

    void dfs(
        set<int> queens, unordered_set<int> xy_diff, unordered_set<int> xy_sum)
    {
        int p = queens.size();
        if (sz == p) {
            vector<string> temp(sz, string(sz, '.'));
            set<int>::iterator it = queens.begin();
            for (int i = 0; i < queens.size(); ++i, ++it) {
                temp[i][*it] = 'Q';
            }
            res.push_back(temp);
            return;
        }
        for (int q = sz - 1; q >= 0; --q) {
            if (!queens.count(q) && !xy_diff.count(p - q)
                && !xy_sum.count(p + q)) {
                queens.insert(q);
                xy_diff.insert(p - q);
                xy_sum.insert(p + q);
                dfs(queens, xy_diff, xy_sum);
            }
        }
    }
};
