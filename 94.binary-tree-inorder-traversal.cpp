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
            // vector<int> res;
            // dfs(root, res);
            // return res;
            return bfs(root);
        }

        void dfs(TreeNode* root, vector<int>& res) {
            if (root) {
                if (root -> left) dfs(root -> left, res);
                res.push_back (root -> val);
                if (root -> right) dfs(root -> right, res);
            }
        }

        vector<int> bfs(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> stack;
            TreeNode* curr = root;
            while (curr || !stack.empty()) {
                while (curr) {
                    stack.push(curr);
                    curr = curr -> left;
                }
                curr = stack.top();
                stack.pop();
                res.push_back(curr -> val);
                curr = curr -> right;
            }
            return res;
        }

};
