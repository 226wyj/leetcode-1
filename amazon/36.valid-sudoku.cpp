class Solution {
#define B(i, j) (3 * (i / 3) + j / 3)
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            if (board.empty() || board[0].empty()) {
                return false; 
            }

            int m = board.size(), n = board[0].size();

            vector<vector<bool>> row(m, vector<bool>(n, false));
            vector<vector<bool>> col(m, vector<bool>(n, false));
            vector<vector<bool>> box(m, vector<bool>(n, false));
            
            for (int i = 0; i < m; ++i) {
               for (int j = 0; j < n; ++j) {
                    if (board[i][j] == '.') {
                        continue; 
                    }

                    int value = board[i][j] - '1';
                    if (row[i][value] || col[value][j] || box[B(i, j)][value]) {
                        return false; 
                    } else {
                        row[i][value] = true;
                        col[value][j] = true;
                        box[B(i, j)][value] = true;
                    }
               } 
            }
            return true;
        }
};
