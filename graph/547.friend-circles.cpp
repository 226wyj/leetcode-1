class Solution {
    public:
        int findCircleNum(vector<vector<int>>& M) {
            vector<int> visited(M.size());
            unsigned count = 0;
            // all people will be covered in the first row/col
            // so we just need to check each of the element of the
            // first row. if we identify they are friends with others
            // mark the other as true in visited set (here uses vector for
            // simplicity).
            for (unsigned i = 0; i < M.size(); ++i) {
                if (visited[i] == 0) {
                    dfs(M, visited, i);
                    count++;
                }
            }
            return count;
        }

        // in the dfs we find current's friends, if we find one
        // -- meaning i, j are friends and M[i][j] == 1, then
        // set the set to 1.
        void dfs(vector<vector<int>>& M, vector<int>& visited, unsigned i) {
            for (unsigned j = 0; j < M.size(); ++j) {
                if (M[i][j] == 1 && visited[j] == 0) {
                    visited[j] = 1;
                    dfs(M, visited, j);
                }
            }

        }
};
