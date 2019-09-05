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
        if (!root)
            return {};
        queue<TreeNode*> q{ { root } };
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.back()->val);
            int level_size = q.size();
            while (level_size--) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        return res;
    }
};
