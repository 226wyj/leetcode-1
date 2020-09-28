/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  void dfs(TreeNode* root, vector<int>& res, int depth = 0) {
    if (!root) return ;
    // because traverse from head -> right -> left, the first node is always the right most node of the depth
    // only choose the 
    cout << root -> val << endl;
    if (depth == res.size()) res.push_back(root -> val);
    dfs(root -> right, res, depth + 1);
    dfs(root -> left, res, depth + 1);
  }
  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    dfs(root, res);
    return res;
  }
};
