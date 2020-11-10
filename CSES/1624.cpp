
// Problem : Chessboard and Queens
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1624
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
string g[8];
bool d1[16], d2[16];
int main() {
	for (int i = 0; i < 8; ++i) cin >> g[i];
	int p[8], res = 0;
	iota(p, p + 8, 0); // fill from 0 to 7
	do {
		bool valid = 1;
		for (int i = 0; i < 8; ++i) {
			valid &= g[i][p[i]] == '.'; // *
		}
		memset(d1, 0, 15);
		memset(d2, 0, 15);
		for (int i = 0; i < 8; ++i) {
			if (d1[i + p[i]] || d2[i + 7 - p[i]]) valid = 0;
			d1[i + p[i]] = d2[i + 7 - p[i]] = 1;
		}
		res += valid;
	} while (next_permutation(p, p + 8));
	cout << res;
	return 0;
}