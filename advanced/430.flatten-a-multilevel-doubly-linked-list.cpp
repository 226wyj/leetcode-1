/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
    // dfs: flatten the node "head" and return the tail in its child (if exists)
    // the tail means the last node after flattening "head"

    // Five situations:
    Node* dfs(Node* head) {
        // 1. null - no need to flatten, just return it
        if (!head) return head;
        if (head -> child == NULL) {
            // 2. no child, no next - no need to flatten, it is the last element, just return it
            if (head -> next == NULL) return head;
            // 3. no child, next - no need to flatten, go next
            return dfs(head -> next);
        } else {
            Node *child = head -> child;
            head -> child = NULL;
            Node *next = head -> next;
            Node *childtail = dfs(child);
            head -> next = child;
            child -> prev = head;
            // 4. child, no next - flatten the child and done
            if (next != NULL) {
                childtail -> next = next;
                next -> prev = childtail;
                return dfs(next);
            }
            // 5. child, next - flatten the child, connect it with the next, go next
            return childtail;
        }
    }

    };
