
// Problem : Two Sets
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1092
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {	
	int n;
	cin >> n;
	LL sm = ((1 + 0ll + n) * n) / 2;
	if (sm % 2 == 0) {
		cout << "YES" << endl;
		LL target = sm / 2;
		int curr = n, cnt = 0;
		vector<bool> mark(n + 1, false);
		while (target != 0) {
			if (curr > target)
				curr = target;
			mark[curr] = true;
			cnt ++;
			target -= curr;
			curr --;
		}
		cout << cnt << endl;
		
		for (int i = 1; i <= n; ++i)
			if (mark[i]) cout << i << " ";
		cout << endl;
		cout << n - cnt << endl;
		for (int i = 1; i <= n; ++i)
			if (!mark[i]) cout << i << " ";
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}