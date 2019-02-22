class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) {
            if (board.size() == 0 || board[0].size() == 0) return false;
            if (word.size() == 0) return true;
            for (unsigned i = 0; i < board.size(); ++i)
                for (unsigned j = 0; j < board[0].size(); ++j)
                    if (dfs(i, j, 0, board, word)) return true;
            return false;
        }
        bool dfs(unsigned i, unsigned j, unsigned pos, vector<vector<char>>& board, string word) {
            if (pos == word.size()) return true;
            if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
            bool ret = false;
            if (board[i][j] == word[pos]) {
                char t = board[i][j];
                board[i][j] = '\0';
                ret = (	dfs(i + 1, j, pos + 1, board, word) ||
                        dfs(i - 1, j, pos + 1, board, word) ||
                        dfs(i, j + 1, pos + 1, board, word) ||
                        dfs(i, j - 1, pos + 1, board, word) );
                board[i][j] = t;
            }
            return ret;
        }
};
