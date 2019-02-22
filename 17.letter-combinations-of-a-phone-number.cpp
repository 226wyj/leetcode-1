class Solution {
    public:
        vector<string> retval;
        map<int, string> dict = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        vector<string> letterCombinations(string digits) {
            if (digits == "") return retval;
            dfs("", 0, digits);
            return retval;
        }

        void dfs(string temp, int index, string digits) {
            if (temp.size() == digits.size()) {
                retval.push_back(temp);
                return;
            } else {
                for (char c : dict[digits[index]]) {
                    temp.push_back(c);
                    dfs(temp, index + 1, digits);
                    temp.pop_back();
                }
            }
        }
};
