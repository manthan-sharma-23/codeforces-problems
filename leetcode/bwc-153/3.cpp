#include <climits>
#include <vector>

using namespace std;

class Solution {
  typedef long long ll;
  const ll LARGE = 1e17;

public:
  long long minimumCost(vector<int> &nums, vector<int> &cost, int k) {
    int n = nums.size();

    vector<ll> prefixNums(n + 1, 0);
    for (int i = 1; i <= n; i++)
      prefixNums[i] = prefixNums[i - 1] + (ll)nums[i - 1];

    vector<ll> prefixCost(n + 1, 0);
    for (int i = 1; i <= n; i++)
      prefixCost[i] = prefixCost[i - 1] + (ll)cost[i - 1];

    vector<ll> dp(n + 1, LARGE);
    dp[0] = 0;
    for (int start = 1; start <= n; start++) {
      for (int end = start; end <= n; end++) {
        ll subArrayScore = ((prefixNums[end] - prefixNums[start - 1]) + k) *
                           (prefixCost[n] - prefixCost[start - 1]);
        dp[end] = min<ll>(dp[start - 1] + subArrayScore, dp[end]);
      }
    }

    return dp[n];
  }
};