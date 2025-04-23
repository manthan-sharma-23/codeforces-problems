#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  typedef long long ll;
  vector<long long> resultArray(vector<int> &nums, int k) {
    int n = nums.size();

    vector<vector<ll>> dp(n, vector<ll>(k, 0LL));
    vector<ll> res(k, 0);

    dp[0][nums[0] % k]++;

    for (int i = 1; i < n; i++) {
      int t = nums[i] % k;
      for (int rem = 0; rem < k; rem++)
        dp[i][(rem * t) % k] += dp[i - 1][rem];
      dp[i][t]++;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        res[j] += dp[i][j];
      }
    }

    return res;
  }
};
