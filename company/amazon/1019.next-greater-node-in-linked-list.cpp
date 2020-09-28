/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  vector<int> nextLargerNodes(ListNode *head) {
    vector<int> f;
    stack<int> st; // store current maximum
    for (auto curr = head; curr; curr = curr->next) {
      while (!st.empty() && f[st.top()] < curr->val) {
        f[st.top()] = curr -> val;
        st.pop();
      }
      st.push(f.size());
      f.push_back(curr->val);
    }
    while (!st.empty()) {
      f[st.top()] = 0;
      st.pop();
    }
    return f;
  }
};
// @lc code=end
