class Solution {
private:
    vector<string> ret;
    unordered_map<int, string> dict = {
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" },
    };

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return ret;
        helper("", 0, digits);
        return ret;
    }

    void helper(string curr, int index, string digits)
    {
        if (curr.size() == digits.size()) {
            ret.push_back(curr);
            return;
        } else {
            for (char c : dict[digits[index]]) {
                curr.push_back(c);
                helper(curr, index + 1, digits);
                curr.pop_back();
            }
        }
    }
};
