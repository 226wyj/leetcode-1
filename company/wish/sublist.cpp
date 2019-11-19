#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<int> t = {1,3,5,4,1};
  int n = t.size();
  int target = 4; // 4 -> 1

  int l = 0, r = 0, res = n + 1;
  int curr = 0;
  while (r < n) {
      curr = t[l];
      while (r + 1 < n && curr < target)
          curr += t[++r];
      if (curr == target)
        res = min(res, r - l + 1);
      l = ++r; // move to next one
  }
  cout << res << endl;
  return 0;
}
