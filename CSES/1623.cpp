
// Problem : Apple Division
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1623
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int N = 20;
typedef long long LL;
LL num[N];

int main() {
	int n;
	cin >> n;
	LL sum = 0, res = 0;
	for (int i = 0; i < n; ++i) cin >> num[i], sum += num[i];
	for (int i = 0; i < 1 << n; ++i) {
		LL curr = 0;
		for (int j = 0; j < n; ++j) {
			if (i >> j & 1) curr += num[j];
		}
		if (curr <= sum / 2) res = max(res, curr);
	}
	cout << sum - 2 * res;
	return 0;
}