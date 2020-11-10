
// Problem : Task
// Contest : Google Coding Competitions - Round B 2020 - Kick Start 2020
// URL :
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc#problem
// Memory Limit : 1024 MB
// Time Limit : 10000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e9;

int main() {
  int T;
  cin >> T;
  string str;
  for (int t = 1; t <= T; ++t) {
    ll x = 0, y = 0;
    cin >> str;
    vector<ll> mul = {1};
    for (char c : str) {
      if (c >= '2' && c <= '9')
        mul.push_back(mul.back() * (c - '0') % N);
      else if (c == 'E')
        x = (x + mul.back()) % N;
      else if (c == 'W')
        x = ((x - mul.back()) % N + N) % N;
      else if (c == 'S')
        y = (y + mul.back()) % N;
      else if (c == 'N')
        y = ((y - mul.back()) % N + N) % N;
      else if (c == '(')
        continue;
      else if (c == ')')
        mul.pop_back();
    }
    printf("Case #%d: %lld %lld\n", t, x + 1, y + 1);
  }
  return 0;
}