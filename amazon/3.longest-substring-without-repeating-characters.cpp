class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i < s.size(); ++i) {
            // there is a repeat from dict[s[i]] to i, so update start to
            // dict[s[i]]
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
