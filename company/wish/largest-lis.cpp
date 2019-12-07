#include <deque>
#include <iostream>
#include <vector>
using namespace std;
// given a list and a target number, find the smallest subarray whose sum is
// greater than target
int find_smallest_len(vector<int>& A, int K)
{
    int n = A.size(), res = INT_MAX;
    deque<int> dq;
    vector<int> sums(n + 1);
    for (int i = 1; i <= n; ++i)
        sums[i] = sums[i - 1] + A[i - 1];
    for (int i = 0; i <= n; ++i) {
        while (!dq.empty() && sums[i] - sums[dq.front()] >= K) {
            res = min(res, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && sums[i] <= sums[dq.back()]) {
            dq.pop_back();
        }
        std::cout << sums[i] << std::endl;
        dq.push_back(i);
    }
    return res == INT_MAX ? -1 : res;
}
int main()
{
    // int test[] = { 3, 1, 2, 5, 4 };
    vector<int> test = { 3, 1, 2, 5, 4 };
    int n = 5;
    cout << find_smallest_len(test, n) << endl;
    /*
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
    */
    return 0;
}
