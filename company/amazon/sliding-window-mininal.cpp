/*
 * sliding-window-mininal.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;
int a[100];
int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  deque<int> dq;
  vector<int> res;
  for (int i = 0; i < n; ++i) {
    if (dq.empty())
      dq.push_back(i);
    else {
      while (!dq.empty() && dq.front() <= i - k) {
        dq.pop_front();
      }
      while (!dq.empty() && (a[dq.back()] > a[i])) {
        dq.pop_back();
      }
      dq.push_back(i);
    }
    if (i >= k - 1)
      res.push_back(a[dq.front()]);
  }
  for (int i : res) {
    cout << i << endl;
  }
  return 0;
}
