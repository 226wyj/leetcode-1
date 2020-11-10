#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int num[N];

int main() {
  int n, k, T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> num[i];
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
    	if (num[i] > k) cnt ++;
    	else if (num[i] < k) cnt --;
    }
    int res = n;
    for (int i = 0, j = 0, curr = 0; i < n; ++i) {
      if (num[i] > k) curr ++;
      else if (num[i] < k) curr --;
      if (curr == cnt)
        res = min(res, i - j + 1);
      else if (curr > cnt) {
        if (j < n && num[j] > k) curr --;
        if (j < n && num[j] < k) curr ++;
        j++;
      }
	  printf("curr:%d\n", curr);
    }
    cout << n - res << endl;
  }

  return 0;
}