
// Problem : Grid Paths
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1625
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int res = 0;
string s;
bool vis[7][7];

bool inline e(int i, int j) {
	return i >= 0 && i < 7 && j >= 0 && j < 7 && !vis[i][j];
}

void dfs(int i, int j, int a = 0) {
	if (i == 6 && j == 0)	{
		if (a == 48) res ++;
		return;
	}
	vis[i][j] = 1;
	if (s[a] == '?' || s[a] == 'L') {
		if (j && !vis[i][j - 1]) {
			if (!(!e(i, j - 2) && e(i + 1, j - 1) && e(i - 1, j - 1)))
				dfs(i, j - 1, a + 1);
		}
	}
	if (s[a] == '?' || s[a] == 'R') {
		if (j < 6 && !vis[i][j + 1]) {
			if (!(!e(i, j + 2) && e(i + 1, j + 1) && e(i - 1, j + 1)))
				dfs(i, j + 1, a + 1);
		}
	}
	if (s[a] == '?' || s[a] == 'U') {
		if (i && !vis[i - 1][j]) {
			if (!(!e(i - 2, j) && e(i - 1, j + 1) && e(i - 1, j - 1)))
				dfs(i - 1, j, a + 1);
		}
	}
	if (s[a] == '?' || s[a] == 'D') {
		if (i < 6 && !vis[i + 1][j]) {
			if (!(!e(i + 2, j) && e(i + 1, j + 1) && e(i + 1, j - 1)))
				dfs(i + 1, j, a + 1);
		}
	}
	vis[i][j] = 0;
}
int main() {
	cin >> s;
	dfs(0, 0);
	cout << res;
	return 0;
}