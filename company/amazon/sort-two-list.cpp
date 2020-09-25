#include <bits/stdc++.h>

using namespace std;

int a[100], b[10];

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	for (int i = m - 1, j = n - 1, tail = m + n - 1; ~i && ~j; ) {
		if (a[i] > b[j]) {
			a[tail--] = a[i];
			i--;
		} else {
			a[tail--] = a[j];
			j--;
		}
	}
	for (int i = 0; i < m + n; ++i) cout << a[i] << " ";
	return 0;
}