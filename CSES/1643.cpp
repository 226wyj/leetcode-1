
// Problem : Maximum Subarray Sum
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1643
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
	int n;
	cin >> n;
	LL gmax = -1e9, lmax = -1e9;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		lmax = max(lmax + a, a + 0ll);
		gmax = max(gmax, lmax);
	}
	cout << gmax;
	return 0;
}