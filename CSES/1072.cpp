
// Problem : Two Knights
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1072
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL nChoosek(int n, int k) {
  if (k > n) return 0;
  if (k * 2 > n) k = n - k;
  if (k == 0) return 1;

  LL result = n;
  for (int i = 2; i <= k; ++i) {
    result *= (n - i + 1);
    result /= i;
  }
  return result;
}


int main() {
  int k;
  cin >> k;
  for (int i = 1, fact = 2; i <= k; ++i) {
  	// 0, 0, 8(2*4),  24(4*6)
  	if (i <= 2) cout << nChoosek(i * i, 2) << endl;
    else {
    	cout << nChoosek(i * i, 2) - fact * (fact + 2) << endl;
    	fact += 2;
    }
  }
  return 0;
}