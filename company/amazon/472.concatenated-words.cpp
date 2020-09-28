/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

// @lc code=start
class Solution {
public:
  struct Node {
    Node *next[26];
    bool end = false;
  };
  Node *root;
  void add(string &w) {
    Node *curr = root;
    for (char c : w) {
      if (!curr->next[c - 'a'])
        curr->next[c - 'a'] = new Node();
      curr = curr->next[c - 'a'];
    }
    curr->end = true;
  }

  bool find(string w, int idx, int cnt) {
    Node *curr = root;
    int n = w.size();
    for (int i = idx; i < n; ++i) {
      if (!curr->next[w[i] - 'a'])
        return false;
      if (curr->next[w[i] - 'a']->end) {
        if (i == n - 1)
          return cnt >= 1;
        if (find(w, i + 1, cnt + 1))
          return true;
      }
      curr = curr->next[w[i] - 'a'];
    }
    return false;
  }
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    root = new Node();
    vector<string> res;
    for (string &w : words) {
      add(w);
    }
    for (string &w : words) {
      if (find(w, 0, 0))
        res.push_back(w);
    }
    return res;
  }
};
// @lc code=end
