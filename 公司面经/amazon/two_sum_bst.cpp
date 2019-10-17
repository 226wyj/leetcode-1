/*
 * two_sum_bst.cpp
 * Copyright (C) 2019 advpetc <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int d)
        : data(d)
    {
    }
};
/*! \brief count
 *
 *  count the total number of pairs of nodes added up to target
 *
 * \param root1 first bst
 * \param root2 second bst
 * \param target target num to be summed up to
 * \return total pairs
 */
int countPairs(Node* root1, Node* root2, int target)
{
    if (!root1 || !root2)
        return 0;
    stack<Node*> st1, st2;
    Node *top1, *top2;
    int count = 0;
    while (true) {
        while (root1) {
            st1.push(root1);
            root1 = root1->left;
        }
        while (root2) {
            st2.push(root2);
            root2 = root2->right;
        }

        if (st1.empty() || st2.empty())
            return res;
        top1 = st1.top();
        top2 = st2.top();
        if ((top1->data + top2->data) == target) {
            count++;
            st1.pop();
            st2.pop();
            root1 = top1->right;
            root2 = top2->left;
        } else if ((top1->data + top2->data) < target) {
            st1.pop();
            root1 = top1->right;
        } else {
            st2.pop();
            root2 = top2->left;
        }
    }
    return count;
}
int main(int argc, char* argv[]) { return 0; }
