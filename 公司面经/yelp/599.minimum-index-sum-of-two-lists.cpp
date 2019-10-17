class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); ++i) {
            m[list1[i]] = i;
        }

        int min_sum = INT_MAX;
        vector<string> res;
        for (int i = 0; i <= min((int)list2.size() - 1, min_sum); ++i) {
            if (m.count(list2[i]) > 0) {
                int curr_sum = m[list2[i]] + i;
                if (min_sum > curr_sum) {
                    res = { list2[i] };
                    min_sum = curr_sum;
                } else if (curr_sum == min_sum) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};
