
// Problem : Repetitions
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1069
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main() {
	string str;
	cin >> str;
	int res = 1;
	for (int i = 0; i + 1 < str.length();) {
		int j = i + 1;
		while (j < str.length() && str[i] == str[j]) j++;
		res = max(res, j - i);
		i = j;
	}
	cout << res;
	return 0;
}