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
    bool isCompleteTree(TreeNode* root)
    {
        queue<TreeNode*> q{ { root } };
        bool pre = false;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node)
                pre = true;
            else if (pre)
                // if you see a null, then all the nodes after it should be null
                // or it will not be complete
                return false;
            else {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};
