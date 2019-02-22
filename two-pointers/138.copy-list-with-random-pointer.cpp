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
            if (head == NULL) return NULL;
            if (visited.find(head) != visited.end()) return visited[head];
            RandomListNode* node = new RandomListNode(head -> label);
            visited[head] = node;
            node -> next = copyRandomList(head -> next);
            node -> random = copyRandomList(head -> random);
            return node;
        }
};
