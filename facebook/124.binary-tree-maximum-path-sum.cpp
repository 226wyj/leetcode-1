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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root)
    {
        helper(root);
        return res;
    }
    int helper(TreeNode* root)
    {
        if (!root)
            return 0;
        int left = max(helper(root->left), 0);
        int right = max(helper(root->right), 0);
        res = max(left + right + root->val, res);
        return max(left, right) + res;
    }
};
