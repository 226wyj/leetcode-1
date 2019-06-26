class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        string str;
        TrieNode()
            : str("")
        {
            for (auto& a : child)
                a = NULL;
        }
    };

    struct Trie {
        TrieNode* root;
        Trie()
            : root(new TrieNode())
        {
        }
        void insert(string s)
        {
            TrieNode* p = root;
            for (const char& a : s) {
                int i = a - 'a';
                if (!p->child[i])
                    p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty())
            return res;
        vector<vector<bool>> visited(
            board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        for (const auto& a : words) {
            T.insert(a);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (T.root->child[board[i][j] - 'a'])
                    search(board, T.root->child[board[i][j] - 'a'], i, j,
                        visited, res);
            }
        }
        return res;
    }

    void search(vector<vector<char>>& board, TrieNode* p, int i, int j,
        vector<vector<bool>>& visited, vector<string>& res)
    {
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();
        }
        int d[][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        visited[i][j] = true;
        for (const auto& a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()
                && !visited[nx][ny] && p->child[board[nx][ny] - 'a'])
                search(
                    board, p->child[board[nx][ny] - 'a'], nx, ny, visited, res);
            ;
        }
        visited[i][j] = false;
    }
};
