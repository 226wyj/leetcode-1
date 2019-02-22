class Solution {
    public:
        vector<vector<int>> ret;
        vector<vector<int>> permute(vector<int>& nums) {
            vector<bool> used(nums.size(), false);
            sort(nums.begin(), nums.end());
            dfs({}, used, nums);
            return ret;
        }

        void dfs(vector<int> curr, vector<bool> used, vector<int>& nums) {
            if (curr.size() == nums.size()) ret.push_back(curr);
            else {
                for (unsigned i = 0; i < nums.size(); ++i) {
                    // already used; assume there is no duplicate in input
                    if (used[i])
                            //|| i > 0 && nums[i - 1] == nums[i] && !nums[i - 1])
                        continue;
                    else {
                        curr.push_back(nums[i]);
                        used[i] = true;
                        dfs(curr, used, nums);
                        used[i] = false;
                        curr.pop_back();
                    }
                }
            }
        }

};
