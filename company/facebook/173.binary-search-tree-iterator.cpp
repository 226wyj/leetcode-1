/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root)
    {
        while (root) {
            data.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode* curr = data.top();
        for (TreeNode* curr = curr -> right; curr; curr = curr -> right) {
            data.push(curr);
        }
        return curr -> val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !data.empty();
    }

private:
    stack<TreeNode*> data;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
