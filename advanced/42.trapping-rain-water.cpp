class Solution {
public:
    int trap(vector<int>& height)
    {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty() || height[st.top()] >= height[i]) {
                st.push(i);
            } else {
                int curr_top = st.top();
                st.pop();
                if (!st.empty()) {
                    res += (min(height[i], height[st.top()]) - height[curr_top])
                        * (i - st.top() - 1);
                }
            }
        }
        return res;
    }
};
