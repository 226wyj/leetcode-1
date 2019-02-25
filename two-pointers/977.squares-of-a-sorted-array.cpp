class Solution {
    public:
        vector<int> sortedSquares(vector<int>& A) {
            int i = 0, j = A.size() - 1;
            vector<int> ret(A.size());
            for (int t = A.size() - 1; t >= 0; --t) {
                if (abs(A[i]) > abs(A[j])) {
                    ret[t] = A[i] * A[i];
                    i++;
                } else {
                    ret[t] = A[j] * A[j];
                    j--;
                }
            }
            return ret;
        }
};
