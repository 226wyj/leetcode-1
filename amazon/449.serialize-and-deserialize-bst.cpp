/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    /*! \brief Serialzer
     *
     *  overrided: root left right serailzer
     *
     * \param root root node
     * \param os string
     * \return void
     */
    void serialize(TreeNode* root, ostringstream& os)
    {
        if (!root)
            os << "# ";
        else {
            os << root->val << " ";
            serialize(root->left, os);
            serialize(root->right, os);
        }
    }

    /*! \brief Deserailzer for a string
     *
     *  overrided: create node from root left right
     *
     * \param is input string
     * \return created nodes from string
     */
    TreeNode* deserialize(istringstream& is)
    {
        string val = "";
        is >> val;
        if (val == "#")
            return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserialize(is);
        node->right = deserialize(is);
        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        ostringstream os;
        serialize(root, os);
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        istringstream is(data);
        return deserialize(is);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
