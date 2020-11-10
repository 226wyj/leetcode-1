
// Problem : Restaurant Customers
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1619
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int n;
const int N = 2 * 1e5 + 10;
pair<LL, LL> t[N];
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t[i].first >> t[i].second;
	}
	sort(t, t + n);
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; ++i) {
		auto p = t[i];
		if (!pq.empty() && pq.top() <= p.first) pq.pop();
		pq.push(p.second);
	}
	cout << pq.size();
	return 0;
}