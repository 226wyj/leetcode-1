/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        unordered_map<Node*, Node*> m;
        return dfs(node, m);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& m)
    {
        if (!node)
            return NULL;
        if (m.count(node))
            return m[node];
        Node* clone = new Node(node->val);
        m[node] = clone;
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, m));
        }
        return clone;
    }
};
