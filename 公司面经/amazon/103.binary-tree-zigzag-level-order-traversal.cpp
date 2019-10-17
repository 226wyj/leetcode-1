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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if (!root)
            return {};
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        int order = 1;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                level.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                q.pop();
            }

            if (order % 2 == 0) {
                reverse(level.begin(), level.end());
            }
            ret.push_back(level);
            order++;
        }
        return ret;
    }
};
