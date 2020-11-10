
// Problem : Ferris Wheel
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1090
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
const int N = 2 * 1e5 + 10;
int p[N];

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) cin >> p[i];
  sort(p, p + n);
  int cnt = 0;
  for (int i = 0, j = n - 1; i < j; ++i, --j) {
  	while (i < j && p[i] + p[j] > x) {
  		j--;
  	}
  	if (i >= j) break;
  	cnt ++;
  }
  cout << n - cnt;
  return 0;
}