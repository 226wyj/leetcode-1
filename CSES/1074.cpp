
// Problem : Stick Lengths
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1074
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 2 * 1e5 + 10;
LL a[N];

int kth(int l, int r, int k) {
	if (l >= r) return a[l];
	int i = l - 1, j = r + 1, x = a[(l+ 0ll + r) >> 1];
	while (i < j) {
		while (a[++i] > x) ;
		while (a[--j] < x) ;
		if (i < j) swap(a[i], a[j]);
	}
	int offset = j - l + 1;
	if (offset >= k) return kth(l, j, k);
	return kth(j + 1, r, k - offset);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	LL m = kth(0, n - 1, (n + 1) / 2);
	LL res = 0;
	for (int i = 0; i < n; ++i)
		res += abs(a[i] - m);
	cout << res;
	return 0;
}