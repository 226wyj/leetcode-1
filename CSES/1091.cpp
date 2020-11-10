
// Problem : Concert Tickets
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1091
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, v;
  cin >> n >> m;
  multiset<int> p;
  for (int i = 0; i < n; ++i) {
  	cin >> v;
  	p.insert(v); // make duplicate possible
  }
  for (int i = 0; i < m; ++i) {
    cin >> v;
    auto it = p.upper_bound(v);
    if (it == p.begin()) cout << "-1\n";
    else {
    	cout << *--it << endl;
    	p.erase(it);
    }
  }
  return 0;
}