class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
            if (matrix.size () == 0) return matrix;
            unsigned row = matrix.size(), col = matrix[0].size();
            vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
            queue<pair<int, int>> q;
            // preprocessing: marking each node to 0 if it is zero, and push them into the queue
            for (unsigned i = 0; i < row; ++i)
                for(unsigned j = 0; j < col; ++j) {
                    if (matrix[i][j] == 0) {
                        dist[i][j] = 0;
                        q.push({i, j});
                    }
                }
            int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            while (!q.empty()) {
                pair<int, int> curr = q.front();
                q.pop();
                // check all four directions
                for (unsigned i = 0; i < 4; ++i) {
                    int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
                    if (new_r >= 0 && new_c >= 0 && new_r < row && new_c < col) {
                        // if greater than current zero path, then update
                        if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                            dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                            q.push({new_r, new_c});
                        }
                    }

                }
            }
            return dist;

        }
};
