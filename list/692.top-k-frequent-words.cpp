class Solution {
    public:
        vector<string> topKFrequent(vector<string>& words, int k) {
            map<string, int> cnt;
            for (const string& w : words) {
                ++cnt[w];
            }
            vector<vector<string>> bucket(words.size());
            for (const auto& c : cnt) {
                bucket[c.second].push_back(c.first);
            }
            vector<string> ret;
            for (int i = bucket.size() - 1; k > 0 && i >= 0; --i) {
                if (bucket[i].empty())
                    continue;
                int n = min(k, (int)bucket[i].size());
                ret.insert(ret.end(), bucket[i].begin(), bucket[i].begin() + n);
                k -= n;
            }
            return ret;
        }
};
