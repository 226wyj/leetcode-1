/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    public:
        map<RandomListNode*, RandomListNode*> visited;
        RandomListNode *copyRandomList(RandomListNode *head) {
            return dfs(head);
        }
        // Method 1: treat are Graph and use DFS
        RandomListNode* dfs(RandomListNode *head) {
            if (head == NULL) return NULL;
            if (visited.find(head) != visited.end()) return visited[head];
            RandomListNode* node = new RandomListNode(head -> label);
            visited[head] = node;
            node -> next = copyRandomList(head -> next);
            node -> random = copyRandomList(head -> random);
            return node;
        }

        // Method 2: Store the new node right after the old nodes

        RandomListNode* Optimal(RandomListNode* head) {
            if (!head) return NULL;
            RandomListNode* ptr = head;

            // Inserting the cloned node just next to the original node.
            // If A->B->C is the original linked list,
            // Linked list after weaving cloned nodes would be A->A'->B->B'->C->C'
            while (ptr) {
                RandomListNode* newNode = new RandomListNode(ptr -> label);
                newNode -> next = ptr -> next;
                ptr -> next = newNode;
                ptr = newNode -> next;
            }
            ptr = head;

            // Now link the random pointers of the new nodes created.
            // Iterate the newly created list and use the original nodes' random pointers,
            // to assign references to random pointers for cloned nodes.
            while (ptr) {
                ptr -> next -> random = (ptr -> random) ? ptr -> random -> next : NULL;
                ptr = ptr -> next -> next;
            }

            // Unweave the linked list to get back the original linked list and the cloned list.
            // i.e. A->A'->B->B'->C->C' would be broken to A->B->C and A'->B'->C'
            RandomListNode* ptr_old_list = head;
            RandomListNode* ptr_new_list = head -> next;
            RandomListNode* head_old = head -> next;
            while (ptr_old_list) {
                ptr_old_list -> next = ptr_old_list -> next -> next;
                ptr_new_list -> next = (ptr_new_list) ? ptr_new_list -> next -> next : NULL;
                ptr_old_list = ptr_old_list -> next;
                ptr_new_list = ptr_new_list;
            }
            return head_old;
        }
};
