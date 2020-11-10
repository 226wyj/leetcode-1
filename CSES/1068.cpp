
// Problem : Weird Algorithm
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1068
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;
	while (1) {		
		if (n == 1) {cout << 1; break;}
		cout << n << " ";
		if (n % 2 == 0) n /= 2;
		else n = n * 3 + 1;
	}
	return 0;
}