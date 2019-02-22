class Solution {
    public:
        vector<vector<string>> ret;
        vector<string> curr;
        vector<vector<string>> partition(string s) {
            dfs(s, 0);
            return ret;
        }

        void dfs(string s, int l) {
            if (curr.size() > 0 && l >= s.size()) {
                //vector<string> r = curr;
                ret.push_back(curr);
            }
            for (int i = l; i < s.size(); ++i) {
                if (isPalindrome(s, l, i)) {
                    // if left == right, so single char
                    if (l == i) curr.push_back(string(1, s[i]));
                    else curr.push_back(s.substr(l, i + 1 - l));
                    dfs(s, i + 1);
                    curr.pop_back();
                }
            }
        }

        bool isPalindrome(string str, int l, int r) {
            if (l == r) return true;
            while (l < r) {
                if (str[l++] != str[r--]) return false;
            }
            return true;
        }
};
