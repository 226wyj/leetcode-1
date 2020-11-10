
// Problem : Apartments
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1084
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
int a[N], b[N];
int main() {
	int m, n, k;
	cin >> n >> m >> k;
	
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	int res = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < m && a[i] - b[j] > k) j++;
		if (j < m && b[j] <= a[i] + k)
			++res, ++j;
	}
	cout << res;
	return 0;
}