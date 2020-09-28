/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
class Solution {
public:
  map<string, string> name;
  map<string, string> root;
  string find(string &curr) {
    if (curr != root[curr])
      root[curr] = find(root[curr]);
    return root[curr];
  }
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    vector<vector<string>> res;
    for (auto account : accounts)
      for (int i = 1; i < account.size(); ++i) {
	root[account[i]] = account[i]; // self-assign
	name[account[i]] = account[0]; // email -> name
      }

    for (auto account : accounts) {
      string parent = find(account[1]);
      for (int i = 2; i < account.size(); ++i) {
        root[find(account[i])] = parent;
      }
    }
    map<string, set<string>> children; // root -> children
    for (auto account : accounts) {
      for (int i = 1; i < account.size(); ++i) {
        children[find(account[i])].insert(account[i]);
      }
    }
    for (auto a : children) {
      vector<string> data;
      data.push_back(name[a.first]);
      for (string email : a.second) data.push_back(email);
      res.push_back(data);
    }
    return res;
  }
};
// @lc code=end
