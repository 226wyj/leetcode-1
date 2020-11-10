
// Problem : Palindrome Reorder
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1755
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt[26] = {0};
	for (char c : s) {
		cnt[c - 'A'] ++;
	}
	int odd = 0;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] % 2 == 1) odd ++;
	}
	int n = s.size();
	if (odd > 1) cout << "NO SOLUTION";
	else {
		for (int i = 0, j = n - 1; i < j;) {
			for (int k = 0; k < 26; ++k) {
				if (cnt[k] >= 2) {
					cnt[k] -= 2;
					s[i++] = s[j--] = k + 'A';
				} else if (cnt[k] == 1) {
					s[n / 2] = k + 'A';
				}
			}	
		}
		cout << s;
	}
	return 0;
}