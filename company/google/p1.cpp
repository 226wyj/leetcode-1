/*
 * p1.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    map<int, vector<int>> mp;
    LL N, X;
    cin >> N >> X;
    for (int i = 0; i < N; ++i) {
      LL a;
      cin >> a;
      if (a <= X)
        mp[0].push_back(i + 1);
      else if (a % X == 0)
        mp[a / X].push_back(i + 1);
      else
        mp[a / X + 1].push_back(i + 1);
    }
    cout << "Case #" << t << ": ";
    for (auto it : mp) {
      for (auto e : it.second)
        cout << e << " ";
    }
    cout << "\n";
  }
  return 0;
}
