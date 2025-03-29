#include <climits>
#include <iostream>
#include <string>
#include <vector>

//  needs optimization
using namespace std;

typedef long long ll;
const ll LARGE = 1e16;
class Solution {
public:
  long long minimumCost(vector<int> &nums, vector<int> &cost, int k) {

    int n = nums.size();

    vector<ll> numsPrefix(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      numsPrefix[i] = nums[i - 1] + numsPrefix[i - 1];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, LARGE));

    dp[0][0] = 0;

    for (int parts = 1; parts <= n; parts++) {
      for (int i = parts; i <= n; i++) {
        const ll numsCost = numsPrefix[i] + ((ll)k * parts);
        int costCost = cost[i - 1];

        for (int j = i - 1; j >= parts - 1; j--) {
          dp[i][parts] =
              min(dp[i][parts], (costCost * numsCost) + dp[j][parts - 1]);
          if (j > 0)
            costCost += cost[j - 1];
        }
      }
    }

    ll minCost = LARGE;

    for (int i = 1; i <= n; i++) {
      minCost = min((ll)minCost, dp[n][i]);
    }

    return minCost;
  }
};
