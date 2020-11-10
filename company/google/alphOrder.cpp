#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	
	int res = 0;
	for (int i = 0; i < n;) {
		res ++;
		int j = i, k = i;
		while (j + 1 < n && s[j] <= s[j + 1]) j++;
		while (k + 1 < n && s[k] >= s[k + 1]) k++;
		if (max(j, k) + 1 == n) break;
		i = max(j, k) + 1;
	}
	cout << res;
	return 0;
}

/*
5 0
5 1
3 2
7 3
1 4
1 5
1 6
3 7
4 8
4 9
6 10
6 11
1 12
1 13
*/