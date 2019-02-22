class Solution {
    public:
        vector<string> ret;
        vector<string> generateParenthesis(int n) {
            dfs(n, n, "");
            return ret;
        }

        void dfs(int l, int r, string curr) {
            if (l + r == 0) {
                ret.push_back(curr);
                return;
            } else {
                if (l > r) return;
                if (l > 0) dfs(l - 1, r, curr + "(");
                if (r > 0) dfs(l, r - 1, curr + ")");
            }

        }
};
