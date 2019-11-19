#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int test[] = {3,1,2,5,4};
  int n = 5;
  vector<int> dp(n, 0); // at location i, the largest sum
  int res = -1;
  for (int i = 1; i < n; ++i)
    {
      if (test[i - 1] < test[i])
        dp[i] = dp[i - 1] + test[i];
      else
        dp[i] = test[i];
      res = max(res, dp[i]);
    }
  cout << res;
  return 0;
}
