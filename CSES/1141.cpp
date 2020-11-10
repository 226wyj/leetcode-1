
// Problem : Playlist
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1141
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 2*1e5 + 10;

LL a[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	map<LL, int> idx;
	int res = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		j = max(idx[a[i]], j);
		res = max(res, i - j + 1);
		idx[a[i]] = i + 1;
	}
	cout << res;
	return 0;
}