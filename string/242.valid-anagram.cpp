class Solution {
    public:
        bool isAnagram(string s, string t) {
                int s_map[26] = {0};
                int t_map[26] = {0};
                for (char c : s) s_map[c - 'a']++;
                for (char c : t) t_map[c - 'a']++;
                for (unsigned i = 0; i < 26; ++i)
                    if (s_map[i] != t_map[i]) return false;
                return true;
        }
};
