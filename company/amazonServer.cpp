#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int cnt = 0, n;
string grid[N];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int i, int j, char a) {
  if (i < 0 || j < 0 || i >= n || j >= (int)grid[i].size() || grid[i][j] != a)
    return;

  grid[i][j] = 'z';  // mark
  for (auto d : dir) {
    dfs(i + d[0], j + d[1], a);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> grid[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < (int)grid[i].size(); ++j) {
      if ('a' <= grid[i][j] && grid[i][j] <= 'c') {
        cnt++;
        dfs(i, j, grid[i][j]);
      }
    }
  cout << cnt;
  return 0;
}