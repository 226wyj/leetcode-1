class Solution {
    public:
        // T: all the temperature sorted by time
        vector<int> dailyTemperatures(vector<int>& T) {
            stack<pair<int, int>> s;
            vector<int> ret(T.size(), 0);
            for (unsigned i = 0; i < T.size(); ++i) {
                while (!s.empty() && T[i] > s.top().first) {
                    ret[s.top().second] = i - s.top().second;
                    s.pop();
                }
                s.push(pair<int, int> (T[i], i));
            }
            return ret;
        }
};
