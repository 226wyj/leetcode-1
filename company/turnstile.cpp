#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int main() {
  int n;
  cin >> n;
  int status = 0, startTm = n;
  queue<int> q1, q2; // q1:0, q2:1
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    startTm = min(startTm, a[i]);
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    if (a[i] == startTm && b[i] == 1)
      status = 1;
    if (b[i] == 0)
      q1.push(i);
    else
      q2.push(i);
  }
  int time = 0, cnt = 0;
  vector<int> res(n);
  while (1) {
    bool changed = false;
    if (status == 0 && !q1.empty()) {
      time = max(time, a[q1.front()]);
      res[q1.front()] = time;
      q1.pop();
    } else if (q1.empty()) {
      status = 1;
      changed = true;
    }

    if (status == 1 && !q2.empty()) {
      time = max(time, a[q2.front()]);
      res[q2.front()] = time;
      q2.pop();
    } else if (q2.empty()) {
      status = 0;
      changed = true;
    }
    if (q1.empty() && q2.empty())
      break;
    time++;
    if (!changed) {
      if (cnt == 1) {
        status = !status;
        cnt = 0;
      } else
        cnt++;
    }
  }
  for (int i : res) {
    cout << i << " ";
  }
  /*
  0,1,1,3,3
  0,0,1,1,0

  0,1,1,3,3
  0,1,0,0,1
  */
}
