
// Problem : Sum of Two Values
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1640
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
	LL n, x, v;
	cin >> n >> x;
	map<LL, int> s;
	for (int i = 0; i < (int) n; ++i) {
		cin >> v;
		if (s.count(x - v)) {
			cout << s[x - v] + 1 << " " << i + 1;
			return 0;
		}
		s[v] = i;
	}
	cout << "IMPOSSIBLE";
	return 0;
}