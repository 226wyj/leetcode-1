/*
 * memoUsage.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;

int a[100], b[100];
int main(int argc, char *argv[]) {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  int currMax = 0;
  vector<pair<int, int>> res;
  for (int i = 0; i < n; ++i) {
    int curr = a[i];
    if (curr <= k && curr > currMax) {
      res.clear();
      res.push_back({i, -1});
    } else if (curr == currMax)
      res.push_back({i, -1});
    for (int j = 0; j < m; ++j) {
      if (b[j] <= k && b[j] > currMax) {
        res.clear();
        res.push_back({j, -1});
      } else if (b[j] == currMax)
        res.push_back({j, -1});
      if (curr + b[j] <= k && curr + b[j] > currMax) {
        currMax = curr + b[j];
        res.clear();
        res.push_back({i, j});
      } else if (curr + b[j] == currMax)
        res.push_back({i, j});
    }
  }
  for (auto p : res)
    cout << p.first << " " << p.second << endl;
  return 0;
}
