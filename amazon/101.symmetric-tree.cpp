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
            return root == NULL || helper(root -> left, root -> right);
        }

        /******************************************************************************
        * Function:         bool helper
        * Description:      a simple dfs to check each possible symmetric status
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        bool helper(TreeNode* left, TreeNode* right){
            if (!left || !right) {
                /* if it is true, means all null, if not true, then there must
                 * be one not NULL and the other one is true */
                return left == right;
            } else if (left -> val != right -> val) {
                return false; 
            } else {
                return helper(left -> left, right -> right) && helper(left -> right, right -> left);
            }
        }
};
