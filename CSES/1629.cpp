
// Problem : Movie Festival
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1629
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
const int N = 2 * 1e5 + 10;
pair<LL, LL> t[N];
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t[i].second >> t[i].first;
	}
	sort(t, t + n);
	int res = 0, end = 0;
	for (int i = 0; i < n; ++i) {
		if (t[i].second >= end) {
			end = t[i].first;
			++res;
		}
	}
	cout << res;
	return 0;
}