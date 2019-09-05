class Solution {
public:
    vector<int> findAnagrams(string s, string p)
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
        // int s_sz = s.size(), p_sz = p.size(), cnt = p.size();
        // int left = 0, right = 0;
        // vector<int> m(26, 0), res;
        // for (char c : p)
        // m[c - 'a']++;
        // while (right < s_sz) {
        // m[s[right]]--;
        // if (m[s[right]] == 0) {
        // cnt--;
        //}
        // if (!cnt)
        // res.push_back(left);
        // right++;
        // if (right - left == p_sz && m[s[left]] + 1 >= 0) {
        // m[s[left]]++;
        // cnt++;
        //}
        // left++;
        //}
        // return res;
    }
};
