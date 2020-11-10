/*
 * MaxStack.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;
class MaxStack {
public:
  stack<int> st, mx;

  /** initialize your data structure here. */
  MaxStack() {}

  void push(int x) {
    if (mx.empty() || mx.top() < x)
      mx.push(x);
    else
      mx.push(mx.top());
    st.push(x);
  }

  int pop() {
    mx.pop();
    int res = st.top();
    st.pop();
    return res;
  }

  int top() { return st.top(); }

  int peekMax() { return mx.top(); }

  int popMax() {
    int maxX = mx.top();
    stack<int> tmp;
    while (st.top() != maxX)
      tmp.push(pop());
    pop();
    while (!tmp.empty()) {
      push(tmp.top());
      tmp.pop();
    }
    return maxX;
  }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
int main(int argc, char *argv[]) {
  MaxStack *obj = new MaxStack();
  obj->push(1);
  int param_2 = obj->pop();
  int param_3 = obj->top();
  int param_4 = obj->peekMax();
  int param_5 = obj->popMax();
  return 0;
}
