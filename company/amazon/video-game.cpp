/*
 * video-game.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;
int a[100];
int main(int argc, char *argv[]) {
  int n, cutoff;
  cin >> n >> cutoff;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n, greater<int>());
  int res = 0, rank = 1;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && a[i] < a[i - 1])
      rank = i + 1;
    if (a[i] != 0 && rank <= cutoff)
      res++;
  }
  cout << res;
  return 0;
}
