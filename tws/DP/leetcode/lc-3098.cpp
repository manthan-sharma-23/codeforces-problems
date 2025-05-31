#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n, k;
  const int MOD = 1e9 + 7;
  using ll = long long;
  vector<vector<vector<unordered_map<int, ll>>>> dp;

  ll f(int i, int lastIdx, int len, int minA, const vector<int> &nums) {
    if (len == k)
      return minA;
    if (i == n)
      return 0LL;

    if (dp[i][lastIdx + 1][len].count(minA))
      return dp[i][lastIdx + 1][len][minA];

    ll pick = 0;
    if (lastIdx == -1) {
      pick = f(i + 1, i, len + 1, minA, nums) % MOD;
    } else {
      int diff = abs(nums[i] - nums[lastIdx]);
      pick = f(i + 1, i, len + 1, min(minA, diff), nums) % MOD;
    }

    ll notPick = f(i + 1, lastIdx, len, minA, nums) % MOD;

    return dp[i][lastIdx + 1][len][minA] = (pick + notPick) % MOD;
  }

  int sumOfPowers(vector<int> &nums, int k) {
    this->k = k;
    n = nums.size();
    sort(nums.begin(), nums.end());
    // dp[i][lastIdx + 1][len][minA]

    int maxD = nums[n - 1] - nums[0];

    for (int d = 0; d <= maxD; d++) {
      /* code */
    }

    dp = vector(n + 1, vector(n + 1, vector(k + 1, unordered_map<int, ll>())));
    return f(0, -1, 0, INT_MAX, nums) % MOD;
  }
};
