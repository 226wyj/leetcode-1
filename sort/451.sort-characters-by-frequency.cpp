// related questions: 347, 692 (what if want the char alphabetically if the cha have the
// same frequency
class Solution {
    public:
        string frequencySort(string s) {
                int counts[256] = {0};
                for (char c : s) ++counts[c];
                // [&] can be used to capture all automatic variables odr-used in the body
                // of the lambda by reference and current object by reference if exists,
                // which means counts is captured and we can directly use counts to compare.
                sort(s.begin(), s.end(), [&](char a, char b) {
                        return counts[a] > counts[b] || (counts[a] == counts[b] && a < b);
                });
                return s;
        }
};
