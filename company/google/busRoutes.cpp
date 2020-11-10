
// Problem : Bus Routes
// Contest : Google Coding Competitions - Round B 2020 - Kick Start 2020
// URL :
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83bf
// Memory Limit : 1024 MB
// Time Limit : 10000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int T, n;
ll d;
ll num[1010];

bool works(ll mid) {
  for (int i = 0; i < n; ++i) {
    if (mid % num[i] != 0) 
    	mid += (num[i] - mid % num[i]);
  }
  return mid <= d;
}
	
int main() {
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> n >> d;
    for (int i = 0; i < n; ++i) cin >> num[i];
    ll l = 0, r = d;
    while (l < r) {
      ll m = (l + r + 1) >> 1;
      if (works(m))
        l = m;
      else
        r = m - 1;
    }
    printf("Case #%d: %llu\n", t, l);
  }
  return 0;
}