class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        /* return brute_force(s, p); */
        return sliding_window(s, p);
    }

    vector<int> brute_force(string s, string p)
    {
        if (s.empty())
            return {};
        vector<int> res, cnt(128, 0);
        int ns = s.size(), np = p.size(), i = 0;
        for (char c : p) {
            ++cnt[c];
        }
        while (i < ns) {
            bool success = true;
            vector<int> temp = cnt;
            for (int j = i; j < i + np; ++j) {
                if (--temp[s[j]] < 0) {
                    success = false;
                    break;
                }
            }
            if (success) {
                res.push_back(i);
            }
            ++i;
        }
        return res;
    }

    vector<int> sliding_window(string s, string p)
    {
        if (s.empty())
            return {};
        vector<int> res, m(256, 0);
        int left = 0, right = 0, cnt = p.size(), n = s.size();
        for (char c : p)
            ++m[c];
        while (right < n) {
            if (m[s[right++]]-- >= 1)
                --cnt;
            if (cnt == 0)
                res.push_back(left);
            if (right - left == p.size() && m[s[left++]]++ >= 0)
                ++cnt;
        }
        return res;
    }
};
