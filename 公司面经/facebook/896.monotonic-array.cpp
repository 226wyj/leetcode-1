class Solution {
public:
    bool isMonotonic(vector<int>& A)
    {
        int prev = 0;
        for (int i = 0; i < A.size() - 1; ++i) {
            int c = A[i] - A[i + 1];
            if (c) {
                if (c * prev < 0)
                    return false;
                prev = c;
            }
        }
        return true;
    }
};
