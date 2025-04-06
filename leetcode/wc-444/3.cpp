#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  const int MIN = -8000;
  int n;
  typedef long long ll;
  unordered_map<int,
                unordered_map<int, unordered_map<int, unordered_map<int, int>>>>
      memo;

  int f(int idx, int sum, ll prod, int odd, const vector<int> &nums,
        const int k, const int limit) {
    if (idx == n) {
      if (sum != k || odd == 0)
        return MIN;

      return prod <= limit ? prod : MIN;
    }

    if (memo[idx][sum][prod].count(odd))
      return memo[idx][sum][prod][odd];
    int notPick = f(idx + 1, sum, prod, odd, nums, k, limit);

    if (odd == 0) {
      int pick = f(idx + 1, nums[idx], nums[idx], 1, nums, k, limit);
      return memo[idx][sum][prod][odd] = max(pick, notPick);
    } else {

      int multi = odd == 1 ? -1 : 1;
      int newSum = sum + (multi * nums[idx]);

      int pick = f(idx + 1, newSum, min(prod * nums[idx], limit + 1LL),
                   ((odd == 1) ? 2 : 1), nums, k, limit);
      return memo[idx][sum][prod][odd] = max(pick, notPick);
    }
  }

  int maxProduct(vector<int> &nums, int k, int limit) {
    n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (k > sum || k < -sum)
      return -1;

    ll ans = f(0, 0, 0, 0, nums, k, limit);

    return ans == MIN ? -1 : ans;
  }
};