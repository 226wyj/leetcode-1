
// Problem : Bit Strings
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1617
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int p = 1e9 + 7;

typedef long long LL;

int main() {
	int b;
	cin >> b;
    LL res = 1 % p, a = 2;
    while (b) {
    	if (b & 1) res = res * a % p;
    	a = a * (LL) a % p;
    	b >>= 1;
    }
    cout << res;
	return 0;
}