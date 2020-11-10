/*
 * MaxFreqStack.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;
class FreqStack {
public:
  map<int, int> freq;
  map<int, stack<int>> cnt; // frequency -> element
  int maxfreq;
  FreqStack() { maxfreq = 0; }

  void push(int x) {
    maxfreq = max(maxfreq, ++freq[x]);
    cnt[freq[x]].push(x);
  }

  int pop() {
    int res = cnt[maxfreq].top();
    cnt[maxfreq].pop();
    freq[res]--;
    if (cnt[maxfreq].empty())
      maxfreq--;
    return res;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
int main(int argc, char *argv[]) {
  FreqStack *obj = new FreqStack();
  obj->push(4);
  int param_2 = obj->pop();
  cout << param_2 << endl;
  return 0;
}
