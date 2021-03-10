// Problem: Missing Coin Sum
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2183
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 2*1e5 + 10;

LL a[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	LL res = 1;
	for (int i = 0; i < n && a[i] <= res; ++i) 
		res += a[i];
	cout << res;
	return 0;
}