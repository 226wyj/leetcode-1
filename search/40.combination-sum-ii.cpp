class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(0, target, 0, candidates, curr);
        return ret;
    }

    void dfs(int sum, int target, int index, vector<int>& candidates, vector<int>& curr) {
        if (sum > target) return; // already surpass the target, backtrack
        if (sum == target) ret.push_back(curr);
        int start = index;
        for (; index < candidates.size(); ++index) {
            if (index > start && candidates[index - 1] == candidates[index])
                continue;
            curr.push_back(candidates[index]);
            dfs(sum + candidates[index], target, index + 1, candidates, curr);
            curr.pop_back();
        }
    }
};
