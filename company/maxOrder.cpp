#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int main() {
  int m, n;
  LL a;
  cin >> n;

  priority_queue<LL> pq;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    pq.push(a);
  }
  cin >> m;
  LL res = 0;
  while (m--) {
    int t = pq.top();
    pq.pop();
    res += t;
    if (t - 1 > 0)
      pq.push(t - 1);
  }
  cout << res;
  return 0;
}
