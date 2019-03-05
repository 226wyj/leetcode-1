/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (head == NULL || head -> next == NULL) return head;
            ListNode* succeeding = head -> next;
            head -> next = swapPairs(head -> next -> next);
            succeeding -> next = head;
            return succeeding;
        }
};
