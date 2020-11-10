
// Problem : Creating Strings I
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1622
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	vector<string> res;
	do {
		res.push_back(s);
	} while (next_permutation(s.begin(), s.end()));
	cout << res.size() << endl;
	for (string str : res) cout << str << endl;
	return 0;
}