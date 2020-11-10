
// Problem : Coin Piles
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1754
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
/*
2x_1 + x_2 = t_1
x_1 + 2x_2 = t_2

x_1 - x_2 = t_1 - t_2

x_1 + x_2 = (t_1 + t_2)/3
*/
int main() {
	int n, l, r;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l >> r;
		if (((l + r) % 3 == 0) && (min(l, r) * 2 >= max(l, r))) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}