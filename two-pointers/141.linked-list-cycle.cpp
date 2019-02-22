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
        bool hasCycle(ListNode *head) {
            ListNode *curr = head, *next = NULL;
            while (curr) {
                next = curr -> next;
                // head is never changed
                curr -> next = head;
                curr = next;
                if (curr == head) return true;
            }
            return false;
        }
};
