#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findCoins(vector<int> &numWays) {
    int n = numWays.size();
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    vector<int> coins;

    for (int i = 1; i <= n; ++i) {
      long long expected = (i <= n ? numWays[i - 1] : 0);
      if (dp[i] > expected) {
        return {};
      }
      if (dp[i] < expected) {
        coins.push_back(i);
        for (int j = i; j <= n; ++j) {
          dp[j] += dp[j - i];
        }
        if (dp[i] != expected) {
          return {};
        }
      }
    }
    return coins;
  }
};