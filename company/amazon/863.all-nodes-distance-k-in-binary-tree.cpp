/** Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
            if (!root) {
                return {}; 
            }
            vector<int> ret;
            unordered_map<TreeNode*, TreeNode*> parent;
            unordered_set<TreeNode*> visited;
            findParent(root, parent);
            helper(target, K, parent, visited, ret);
            return ret;
        }

        /******************************************************************************
        * Function:         void findParent
        * Description:      populate parent map: current node -> its parent (root)
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        void findParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent){
            if (!node) {
                return; 
            }
            if (node -> left) {
                parent[node -> left] = node;
            }
            if (node -> right) {
                parent[node -> right] = node;
            }
            findParent(node -> left, parent);
            findParent(node -> right, parent);
        }

        /******************************************************************************
        * Function:         void helper
        * Description:      
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        void helper(TreeNode* node, int K, unordered_map<TreeNode*, TreeNode*>&
                parent, unordered_set<TreeNode*> visited, vector<int>& ret){
            if (visited.count(node)) {
               return;
            }
            visited.insert(node);
            if (K == 0) {
                ret.push_back(node -> val);
                return;
            }
            if (node -> left) {
                helper(node -> left, K - 1, parent, visited, ret);
            }
            if (node -> right) {
                helper(node -> right, K - 1, parent, visited, ret);
            }
            if (parent[node]) {
                helper(parent[node], K - 1, parent, visited, ret);
            }
        }
};
