class Solution {
    public:
        vector<vector<int>> ret;
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> temp;
            sort(candidates.begin(), candidates.end());
            dfs(candidates, temp, 0, target, 0);
            return ret;
        }
        void dfs(vector<int>& cand, vector<int>& temp, int sum, int t, int start) {
            if (t - sum < 0) return;
            if (sum == t)
                ret.push_back(temp);
            for (; start < cand.size(); ++start) {
                temp.push_back(cand[start]);
                sum += cand[start];
                dfs(cand, temp, sum, t, start);
                temp.pop_back();
                sum -= cand[start];
            }
        }
};
