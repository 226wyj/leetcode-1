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
        int max_sum = INT_MIN;
        int maxPathSum(TreeNode* root) {
            max_gain(root);
            return max_sum;
        }
        int max_gain(TreeNode* node) {
            if (!node) return 0;
            int left_gain = max(max_gain(node -> left), 0); // if negative, then drop the node
            int right_gain = max(max_gain(node -> right), 0);
            int local_max = node -> val + left_gain + right_gain;
            max_sum = max(local_max, max_sum);
            return node -> val + max(left_gain, right_gain);
        }
};
