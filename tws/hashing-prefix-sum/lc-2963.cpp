#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  const int MOD = 1e9 + 7;
  long long power(long long base, int exp) {
    long long result = 1;
    while (exp) {
      if (exp % 2)
        result = (result * base) % MOD;
      base = (base * base) % MOD;
      exp /= 2;
    }
    return result;
  }
  int numberOfGoodPartitions(vector<int> &nums) {
    int n = nums.size();

    int parted_subarray = 0;

    unordered_map<int, int> lastOccur;

    for (int i = 0; i < n; i++)
      lastOccur[nums[i]] = i;

    int i = 0;
    int res = 0;

    while (i < n) {
      while (i <= res) {
        res = max(res, lastOccur[nums[i]]);
        i++;
      }
      res = i;
      parted_subarray++;
    }

    return power(2, parted_subarray - 1);
  }
};