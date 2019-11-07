/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        return method1(head);
    }

    /*! \brief Using hashmap
     *
     *  key: origional node -> new node
     *
     * \param head the input linkedlist
     * \return new linkedlist's head
     */
    Node* method1(Node* head)
    {
        if (!head) return NULL;
        Node* res = new Node(head -> val, NULL, NULL);
        Node* node = res, *curr = head -> next;
        unordered_map<Node*, Node*> m;
        m[head] = res;
        // copying next pointer
        while (curr) {
            Node* t = new Node(curr -> val, NULL, NULL);
            node -> next = t;
            m[curr] = t;
            node = node -> next;
            curr = curr -> next;
        }
        node = res, curr = head;
        while (curr) {
            node -> random = m[curr -> random];
            node = node -> next;
            curr = curr -> next;
        }
        return res;
    }
    /*! \brief Recursion
     *
     *  still use hashmap to store the mapping but in a recursive way
     *
     * \param head starting node
     * \return copying linkedlist's head
     */
    Node* method2(Node* head)
    {
        unordered_map<Node*, Node*> m;
        return helper(head, m);
    }

    /******************************************************************************
    * Function:         Node* helper
*                   recursion's helper function
    * Where:
*                   Node* unordered_map<Node*> node - TODO
*                   Node*>& m - TODO
    * Return:           new linkedllist's head
    * Error:            
    *****************************************************************************/
    Node* helper(Node* node, unordered_map<Node*, Node*>& m){
        if (!node) return NULL;
        if (m.count(node)) return m[node];
        Node* ret = new Node(node -> val, NULL, NULL);
        m[node] = ret;
        ret -> next = helper(node -> next, m);
        ret -> random = helper(node -> random, m);
        return res;
    }
};
