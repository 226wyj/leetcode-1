
// Problem: Tower of Hanoi
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2165
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void inline print(int a, int b) {
	cout << a << " " << b << "\n";
}

void dfs(int a, int b, int c, int n) {
	if (n == 1) print(a, c); // no need to move through b
	else {
		dfs(a, c, b, n - 1);
		print(a, c);
		dfs(b, a, c, n - 1);
	}
}


int main() {
	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	dfs(1, 2, 3, n); // move 1 to 3 by 2 for n plates
	return 0;
}