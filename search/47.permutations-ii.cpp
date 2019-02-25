class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        dfs(ret, used, nums, curr);
        return ret;
    }

    void dfs(vector<vector<int>>& ret,
             vector<bool>& used,
             vector<int>& nums,
             vector<int>& curr) {
        if (curr.size() == nums.size()) {
            ret.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if (used[i] || i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            curr.push_back(nums[i]);
            used[i] = true;
            dfs(ret, used, nums, curr);
            used[i] = false;
            curr.pop_back();
        }
    }
};
