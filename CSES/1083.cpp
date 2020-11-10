
// Problem : Missing Number
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1083
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5 + 10;
typedef long long LL;

int num[N];

int main() {
	int n, miss = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) miss ^= i;
	for (int i = 0; i < n; ++i) cin >> num[i];
	for (int i = 0; i < n; ++i) miss ^= num[i];
	cout << miss;
	return 0;
}