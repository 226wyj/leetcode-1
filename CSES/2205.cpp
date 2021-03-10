
// Problem: Gray Code
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2205
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < 1 << n; ++i) {
			string str;
			int j = i ^ i >> 1, cnt = n;
			while (cnt) {
				if (j & 1) str += "1";
				else str += "0";
				j >>= 1;
				cnt --;
			}
			reverse(str.begin(), str.end());
			cout << str << endl;
	}
	return 0;
}