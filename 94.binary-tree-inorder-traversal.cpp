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
    vector<int> inorderTraversal(TreeNode* root) {
	    vector<int> res;
	    dfs(root, res);
	    return res;
    }

    void dfs(TreeNode* root, vector<int>& res) {
	    if (root) {
		    if (root -> left) dfs(root -> left, res);
		    res.push_back (root -> val);
		    if (root -> right) dfs(root -> right, res);
	    }
    }
};
