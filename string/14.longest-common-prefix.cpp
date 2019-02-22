class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.size() == 0) return "";
            string prefix = strs[0];
            for (unsigned i = 0; i < prefix.size(); ++i) {
                char curr = prefix[i];
                for (unsigned j = 1; j < strs.size(); ++j)
                    // there is a differ or one is less than the other
                    if (strs[j][i] != curr || strs[j].size() == i)
                        return strs[j].substr(0, i);
            }
            return prefix;
        }
};
