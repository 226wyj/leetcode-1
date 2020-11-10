
// Problem : Number Spiral
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1071
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

/*
1 1 1*0+1
2 3 2*1 + 1
3 7 3*2 + 1
4 13 4*3 + 1
*/

typedef long long LL;

int main() {
	LL n, y, x;
	cin >> n;
	while (n --) {
		cin >> y >> x;
		LL mx = max(x, y);
		LL diag = mx * (mx - 1) + 1;
		if (mx % 2 == 0) {
			if (x == mx) {				
				diag -= x - y;
			} else {
				diag += y - x;
			}
		} else {
			if (x == mx) {
				diag += x - y;				
			} else {
				diag -= y - x;
			}
		}
		cout << diag << endl;
	}
	
	return 0;
}