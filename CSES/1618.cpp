
// Problem : Trailing Zeros
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1618
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 5; n / i >= 1; i *= 5) {
		cnt += n / i;
	}
	cout << cnt;
	return 0;
}