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
        bool hasPathSum(TreeNode* root, int sum) {
            return !root ? false : topdown(root, sum, 0);
        }

        bool topdown(TreeNode* root, int sum, int curr) {
            if (!root) return curr == sum;
            curr += root -> val;
            return topdown(root -> left, sum, curr) ||
                   topdown(root -> right, sum, curr);
        }
};
