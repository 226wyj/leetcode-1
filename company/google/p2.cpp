/*
 * p2.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define bg second;
#define ed first;
const int N = 1e5 + 10;
pair<LL, LL> a[N];
int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    LL n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> a[i].second >> a[i].first;
    }
    sort(a, a + n);
    LL cnt = 0, last = 0;
    for (int i = 0; i + 1 < n; ++i) {
      if (a[i].ed >= a[i + 1].bg && last < a[i + 1].ed) {
	last = (a[i + 1].ed - a[i].ed) % k + a[i + 1].ed;
	cnt += (a[i + 1].ed - a[i].ed) / k;
      } else if (a[i + 1].bg < last && a[i+1].ed > last) {
	last = (a[i + 1].ed - last) % k + a[i + 1].ed;
	cnt += (a[i + 1].ed - last) / k;
      } else if (a[i + 1].bg < last && a[i+1].ed <= last) {


    }
    cout << "Case #" << t << ": " << cnt << "\n";
  }

  return 0;
}
