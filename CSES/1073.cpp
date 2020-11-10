
// Problem: Towers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1073
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
// equal to find the longest non-decreasing subsequence
int n;
int main() {
	cin >> n;
	vector<int> lowest_ending;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		int last = upper_bound(lowest_ending.begin(), lowest_ending.end(), a) - lowest_ending.begin();
		if (last < lowest_ending.size())
			lowest_ending[last] = a;
		else
			lowest_ending.push_back(a);
	}
	cout << lowest_ending.size();
	return 0;
}