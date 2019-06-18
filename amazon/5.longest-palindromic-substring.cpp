class Solution {
public:
    int start, length;
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
            return s;
        start = 0, length = INT_MIN;
        for (int i = 0; i < s.size(); ++i) {
            expand(i, i, s);
            expand(i, i + 1, s);
        }
        return s.substr(start, length);
    }

    void expand(int left, int right, string& s)
    {
        while (left >= 0 && right <= s.size() - 1 && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - left - 1 > length) {
            start = left + 1;
            length = right - left - 1;
        }
    }
};
