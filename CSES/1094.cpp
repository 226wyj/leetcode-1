
// Problem : Increasing Array
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1094
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
int main() {
	int n, curr, mx;
	long long res = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> curr;
		res += max(0, mx - curr);
		mx = max(mx, curr);
	}
	cout << res;
	return 0;
}