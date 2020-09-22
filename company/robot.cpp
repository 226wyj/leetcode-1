/*
 * robot.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
typedef long long LL;
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<pair<int, int>> pts;
  for (int i = 0; i < n; ++i) {
    pts.push_back({a[i], b[i]});
  }
  sort(pts.begin(), pts.end());
  set<pair<int, int>> s;

  LL best_dist = 1e18;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    int d = ceil(sqrt(best_dist));
    while (pts[i].first - pts[j].first >= best_dist) {
      s.erase({pts[j].second, pts[j].first});
      j += 1;
    }

    auto it1 = s.lower_bound({pts[i].second - d, pts[i].first});
    auto it2 = s.upper_bound({pts[i].second + d, pts[i].first});

    for (auto it = it1; it != it2; ++it) {
      int dx = pts[i].first - it->second;
      int dy = pts[i].second - it->first;
      best_dist = min(best_dist, 1LL * dx * dx + 1LL * dy * dy);
    }
    s.insert({pts[i].second, pts[i].first});
  }

  cout << best_dist;
  return 0;
}
