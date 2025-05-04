#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  using ll = long long;
  int minTravelTime(int l, int n, int k, vector<int> &position,
                    vector<int> &time) {
    int m = n - 1;
    int groups = m - k;

    vector<ll> preD(n + 1, 0), preT(n + 1, 0);
    for (int i = 1; i < n; i++) {
      preD[i] = preD[i - 1] + (position[i] - position[i - 1]);
      preT[i] = preT[i - 1] + time[i - 1];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(groups + 1, LLONG_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= groups && j <= i; j++) {
        for (int c = i - 1; c >= j - 1; c--) {
          if (dp[c][j - 1] == LLONG_MAX)
            continue;
          ll cost = dp[c][j - 1] + (preD[i] - preD[c]) * (preT[i] - preT[c]);
          dp[i][j] = min(dp[i][j], cost);
        }
      }
    }

    return (int)dp[m][groups];
  }
};