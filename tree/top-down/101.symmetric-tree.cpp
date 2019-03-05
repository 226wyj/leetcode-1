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
        bool isSymmetric(TreeNode* root) {
            return topdown(root, root);
        }

        bool topdown(TreeNode* left, TreeNode* right) {
            if (left == NULL || right == NULL) return left == right;
            if (left -> val != right -> val) return false;
            return topdown(left -> left, right -> right);
        }
};
