class Solution {
public:
  struct Node {
    Node *nei[26];
    bool end = false;
  };
  Node *root = new Node();
  void insert(string s) {
    Node *curr = root;
    for (char c : s) {
      if (!curr->nei[c - 'a'])
        curr->nei[c - 'a'] = new Node();
      curr = curr->nei[c - 'a'];
    }
    curr->end = true;
  }

  int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  unordered_set<string> res;
  vector<vector<char>> matrix;
  int m, n;
  bool vis[1010][1010] = {{0}};
  // O(m * n)
  void dfs(int i, int j, string path, Node *curr) {
    if (!curr)
      return;
    if (curr->end)
      res.insert(path);
    vis[i][j] = true;
    for (auto d : dir) {
      int x = i + d[0], y = j + d[1];
      if (x < 0 || x >= m || y < 0 || y >= n ||
          !curr->nei[matrix[x][y] - 'a'] || vis[x][y])
        continue;
      dfs(x, y, path + matrix[x][y], curr->nei[matrix[x][y] - 'a']);
    }
    vis[i][j] = false;
  }
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    m = board.size();
    n = board[0].size();

    for (string &str : words) {
      insert(str);
    }
    matrix = board;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (root->nei[matrix[i][j] - 'a']) {
          string s(1, matrix[i][j]);
          dfs(i, j, s, root->nei[matrix[i][j] - 'a']);
        }
      }
    }
    return vector<string>(res.begin(), res.end());
  }
};
