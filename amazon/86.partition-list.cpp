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
        ListNode* partition(ListNode* head, int x) {
            ListNode* dummy = new ListNode(-1);
            dummy -> next = head;
            ListNode* pre = dummy, *curr = head;
            // pre pointing to last element that is less than x
            while (pre -> next && pre -> next -> val < x) {
                pre = pre -> next; 
            }
            curr = pre;
            while (curr -> next) {
                // swap to left size
                if (curr -> next -> val < x) {
                    ListNode *tmp = curr -> next;
                    curr -> next = tmp -> next;
                    tmp -> next = pre -> next;
                    pre -> next = tmp;
                    pre = pre -> next;
                } else {
                        curr = curr -> next;
                }
            }
            return dummy -> next;
        }
};
