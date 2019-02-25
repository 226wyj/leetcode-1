class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return dfs(pos, s);
    }

    string dfs(int& pos, string s) {
        int num = 0;
        string word = "";
        for (; pos < s.size(); ++pos) {
            char curr = s[pos];
            if (curr == '[') {
                string cs = dfs(++pos, s);
                for(; num > 0; --num) word += cs;
            } else if (curr >= '0' && curr <= '9') {
                num = num * 10 + curr - '0';
            } else if (curr == ']') {
                return word;
            } else {
                word += curr;
            }
        }
        return word;
    }
};
