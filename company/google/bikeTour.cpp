
// Problem : Bike Tour
// Contest : Google Coding Competitions - Round B 2020 - Kick Start 2020
// URL : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6
// Memory Limit : 1024 MB
// Time Limit : 10000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
int nums[110];
int main() {
  int T, n;
  cin >> T;
  for (int t = 0; t < T; ++t){
    cin >> n;
    int cnt = 0;

    for (int i = 0; i < n; ++i)
      cin >> nums[i];

    for (int i = 1; i < n - 1; ++i) {
    	if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) cnt++;
    }

    printf("Case #%d: %d\n", t + 1, cnt);
  }
}
