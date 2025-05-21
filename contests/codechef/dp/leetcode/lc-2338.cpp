#include <bits/stdc++.h>

using namespace std;

using ll = long long;
class Solution {
public:
  int N, M;

  ll dp[1001][1001];
  const int mod = 1e9 + 7;

  ll f(int i, int next) {
    if (i == 0) {
      return 1;
    }

     
  }

  int idealArrays(int n, int maxValue) {
    N = n, M = maxValue;
    memset(dp, -1LL, sizeof(dp));

    return f(0, 1);
  }
};