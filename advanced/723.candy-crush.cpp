class Solution {
    public:
        vector<vector<int>> candyCrush(vector<vector<int>>& board) {
            int m = board.size();
            if (m == 0) return board;
            int n = board[0].size();
            if (n == 0) return board;
            bool todo = false;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n-2; ++j) {
                    int v = abs(board[i][j]);
                    if (v != 0 && v == abs(board[i][j+1]) && v == abs(board[i][j+2])) {
                        board[i][j] = -v;
                        board[i][j+1] = -v;
                        board[i][j+2] = -v;
                        todo = true;
                    }
                }
            }

            for (int j = 0; j < n; ++j) {
                for (int i = 0; i < m-2; ++i) {
                    int v = abs(board[i][j]);
                    if (v != 0 && v == abs(board[i+1][j]) && v == abs(board[i+2][j])) {
                        board[i][j] = -v;
                        board[i+1][j] = -v;
                        board[i+2][j] = -v;
                        todo = true;
                    }
                }
            }
            // gravity part
            if (todo) {
                for (int j = 0; j < n; ++j) {
                    int row = m-1;
                    for (int i = m-1; i >= 0; --i) {
                        if (board[i][j] > 0)
                            board[row--][j] = board[i][j];
                    }
                    while (row >= 0)
                        board[row--][j] = 0;
                }
                return candyCrush(board);
            }
            return board;
        }
};
