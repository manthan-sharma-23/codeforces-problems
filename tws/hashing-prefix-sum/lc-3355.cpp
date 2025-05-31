#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  using ll = long long;
  bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();

    vector<ll> prefs(n, 0LL);

    for (auto q : queries) {

      int l = q[0], r = q[1];

      ++prefs[l];
      if (r + 1 < n)
        prefs[r + 1]--;
    }

    for (int i = 1; i < n; i++) {
      prefs[i] += prefs[i - 1];
    }

    for (int i = 0; i < n; i++) {
      if (nums[i] - prefs[i] > 0)
        return false;
    }

    return true;
  }
};