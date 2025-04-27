#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int n, k;
  int allVisited;
  vector<int> Nums;

  vector<int> digits, remNum, pow10;
  map<pair<int, int>, vector<int>> memo;

  int mod_10(int dig, int k) {
    int result = 1;
    int base = 10 % k;

    while (dig > 0) {
      if (dig % 2 == 1) {
        result = (result * base) % k;
      }
      base = (base * base) % k;
      dig /= 2;
    }

    return result;
  }

  vector<int> f(int mask, int rem) {
    if (memo.find({mask, rem}) != memo.end())
      return memo[{mask, rem}];

    if (mask == allVisited) {
      if (rem % k == 0) {
        return memo[{mask, rem}] = {-1};
      } else {
        return memo[{mask, rem}] = {};
      }
    }

    for (int i = 0; i < n; i++) {
      if (!(mask & (1 << i))) {
        int newRem = (rem * pow10[i] + remNum[i]) % k;
        int newMask = mask | (1 << i);
        auto res = f(newMask, rem);

        if (!res.empty()) {
          res.insert(res.begin(), Nums[i]);
          return memo[{mask, rem}] = res;
        }
      }
    }

    return memo[{mask, rem}] = {};
  }

  vector<int> concatenatedDivisibility(vector<int> &nums, int k) {
    n = nums.size();
    this->k = k;
    Nums = nums;
    sort(nums.begin(), nums.end());
    allVisited = (1 << n) - 1;
    memo.clear();

    for (int i = 0; i < n; i++) {
      digits[i] = to_string(nums[i]).size();
      remNum[i] = nums[i] % k;
      pow10[i] = mod_10(digits[i], k);
    }

    auto path = f(0, 0);

    if (!path.empty())
      path.pop_back();

    return path;
  }
};