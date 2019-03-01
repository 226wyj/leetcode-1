class Solution {
    public:
        int leastBricks(vector<vector<int>>& wall) {
                unordered_map<int, int> m;
                int ret = 0;
                for(const auto& level : wall) {
                    unsigned start = 0;
                    for (unsigned i = 0; i < level.size() - 1; ++i) {
                        int curr = ++m[start += level[i]];
                        ret = max(ret, curr);
                    }
                }
                return wall.size() - ret;
        }
};
