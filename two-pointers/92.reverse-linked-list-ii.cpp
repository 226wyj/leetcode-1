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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0), *pre = dummy;
        dummy -> next = head;
        // make pre pointing to the previous node of m-th node
        for (unsigned i = 1; i < m; ++i)
            pre = pre -> next;
        // starting point to swap
        ListNode* curr = pre -> next;
        for (unsigned i = 0; i < n - m; ++i) {
            ListNode* move = curr -> next;
            curr -> next = move -> next;
            move -> next = pre -> next;
            pre -> next = move;
        }
        return dummy -> next;
    }
};
