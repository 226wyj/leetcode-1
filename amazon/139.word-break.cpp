class Solution {
private:
    unordered_map<string, bool> mem;

public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return helper(s, dict);
    }

    bool helper(string s, unordered_set<string>& wordDict)
    {
        if (mem.count(s) != 0)
            return mem[s];
        if (wordDict.count(s) != 0)
            return mem[s] = true;
        for (int i = 1; i < s.size(); ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (wordDict.count(left) && helper(right, wordDict))
                return mem[s] = true;
        }

        return mem[s] = false;
    }
};
