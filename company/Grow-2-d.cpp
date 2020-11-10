#include <bits/stdc++.h>

using namespace std;

typedef long L;

L countMax(vector<string> upRight) {
  L R = 1e6 + 10, C = 1e6 + 10;
  for (string &s : upRight) {
    int split = 0;
    while (split < (int)s.size() && s[split++] != ' ')
      ;
    L r = stol(s.substr(0, split)), c = stol(s.substr(split));
    R = min(R, r);
    C = min(C, c);
  }
  cout << R << " " << C << endl;
  return R * C;
}

int main() {
  int n;
  cin >> n;
  string str;
  vector<string> input = {"111111 21111", "2 2", "4 2"};
  cout << countMax(input);
  return 0;
}
