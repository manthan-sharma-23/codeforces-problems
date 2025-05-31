#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern) {
    int n = nums.size(), m = pattern.size();
    if (n < m + 1)
      return 0;

    const int base = 37;
    const int mod = 1e9 + 7;

    vector<long long> powBase(m);
    powBase[0] = 1;
    for (int i = 1; i < m; ++i)
      powBase[i] = (powBase[i - 1] * base) % mod;

    long long patternHash = 0;
    for (int i = 0; i < m; ++i) {
      int val = pattern[i] + 2;
      patternHash = (patternHash * base + val) % mod;
    }

    vector<int> rel(n - 1);
    for (int i = 0; i + 1 < n; ++i) {
      if (nums[i] < nums[i + 1])
        rel[i] = 1;
      else if (nums[i] > nums[i + 1])
        rel[i] = -1;
      else
        rel[i] = 0;
    }

    long long hash = 0;
    for (int i = 0; i < m; ++i) {
      int val = rel[i] + 2;
      hash = (hash * base + val) % mod;
    }

    int count = 0;
    if (hash == patternHash)
      ++count;

    for (int i = m; i < rel.size(); ++i) {
      int leftVal = rel[i - m] + 2;
      hash = (hash - leftVal * powBase[m - 1] % mod + mod) % mod;
      hash = (hash * base + (rel[i] + 2)) % mod;
      if (hash == patternHash)
        ++count;
    }

    return count;
  }
};
