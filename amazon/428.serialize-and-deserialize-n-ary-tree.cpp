/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
private:
    /*! \brief helper function for serialize
     *
     *  encode string from n-ary tree
     *
     * \param node input starting node
     * \param res serialized string
     * \return void
     */
    void serialize(Node* node, string& res)
    {
        if (!node) {
            res += "# ";
        } else {
            res += to_string(node->val) + " " + to_string(node->children.size())
                + " ";
            for (auto child : node->children) {
                serialize(child, res);
            }
        }
    }

    /*! \brief helper function for deserialize
     *
     *  decode a string to n-ary tree
     *
     * \param iss input string
     * \return starting root node of the tree
     */
    Node* deserialize(Node* iss)
    {
        string val = "", size = "";
        iss >> val;
        if (val == "#")
            return NULL;
        iss >> size;
        Node* node = new Node(stoi(val), {});
        for (int i = 0; i < stoi(size); ++i) {
            node->children.push_back(deserialize(iss));
        }
        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(Node* root)
    {
        string res;
        serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data)
    {
        istringstream iss(data);
        return deserialize(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
