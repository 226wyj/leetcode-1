/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node *connect(Node *root) {
    Node *curr = root;
    while (curr && curr->left) {
      Node *it = curr;
      while (it) { // fill the nxt ptr for current level
        it->left->next = it->right;
        it->right->next = it->next ? it->next->left : nullptr;
        it = it->next;
      }
      curr = curr->left;
    }
    return root;
  }
};
// @lc code=end
