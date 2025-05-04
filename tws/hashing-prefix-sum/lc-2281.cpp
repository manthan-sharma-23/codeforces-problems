
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int totalStrength(vector<int> &strength) {
    using ll = long long;
    const int MOD = 1e9 + 7;
    int n = strength.size();

    vector<int> prefMin(n + 1, INT_MAX), prefS(n + 1, 0);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      prefS[i] = prefS[i - 1] + strength[i - 1] * i;
      prefMin[i] = min(prefMin[i - 1], strength[i - 1]);
      ans = (ans % MOD + (prefS[i] % MOD * prefMin[i] % MOD) % MOD) % MOD;
    }

    return ans;
  }
};