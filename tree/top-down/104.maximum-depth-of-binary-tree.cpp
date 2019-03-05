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
        int maxDepth(TreeNode* root) {
            topdown(root, 0);
            return maxDepth;
           /* return buttonup(root, 0); */
        }
        // top-down solution
        int maxDepth;
        void topdown(TreeNode* root, int depth) {
            if (!root) return;
            // leaf node
            if (!root -> left && !root -> right)
                maxDepth = max(maxDepth, depth);
            topdown(root -> left, depth + 1);
            topdown(root -> right, depth + 1);
        }

        // button-up solution
        int buttonup(TreeNode* root, int depth) {
            if (!root) return depth;
            return max(buttonup(root -> left, depth + 1),
                       buttonup(root -> right, depth + 1));
        }
};
