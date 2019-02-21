class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
	dfs(board);
    }

    bool dfs(vector<vector<char>>& board) {
	for (unsigned i = 0; i < board.size(); ++i)
		for (unsigned j = 0; j < board[0].size(); ++j)
			if (board[i][j] == '.') {
				for (char c = '1'; c <= '9'; ++c) {
					if (isValid(board, i, j, c)) {
						board[i][j] = c;
						if (dfs(board)) return true;
						else board[i][j] = '.';
					}
				}
				return false;
			}
	return true;
    }

    bool isValid(vector<vector<char>>& board, unsigned row, unsigned col, char c) {
	    for (unsigned i = 0; i < 9; ++i) {
		    // check duplicate of row
		    if (board[i][col] != '.' && board[i][col] == c) return false;
		    // check duplicate of col
		    if (board[row][i] != '.' && board[row][i] == c) return false;
		    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' &&
			board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
			return false;
	    }
	    return true;

    }
};
