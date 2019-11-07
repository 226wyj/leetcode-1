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
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode*> q{ { root } };
        while (!q.empty()) {
            res.push_back(q.back()->val);
            int size = q.size();
            while (size-- > 0) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return res;
    }
};
