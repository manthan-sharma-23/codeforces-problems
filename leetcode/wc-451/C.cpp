#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  using ll = long long;
  vector<vector<int>> adj;
  vector<int> P, F;
  vector<vector<vector<ll>>> dp;

  ll dfs(int u, int b, bool p, int parent) {
    cout << u << " " << b << " " << p << " " << parent << endl;
    if (dp[u][b][p] != -1)
      return dp[u][b][p];

    ll maxP = 0LL;

    if (adj[u].size() == 0) {

      dp[u][b][0] = 0;

      int cost = P[u];
      if (p) {
        cost /= 2;
      }

      if (cost <= b) {
        dp[u][b][1] = (F[u] - cost);
      }

      return max(dp[u][b][1], dp[u][b][0]);
    }

    vector<int> nonPicks, picks;

    for (auto child : adj[u]) {
      ll nonPick = dfs(child, b, 0, u);

      nonPicks.push_back(nonPick);
    }

    dp[u][b][0] = accumulate(nonPicks.begin(), nonPicks.end(), 0);

    for (auto child : adj[u]) {
      ll pick = 0LL;

      int cost = P[u];
      if (p) {
        cost /= 2;
      }

      if (b >= cost)
        pick = F[u] - cost + dfs(child, b - cost, 1, u);

      picks.push_back(pick);
    }

    dp[u][b][1] = accumulate(picks.begin(), picks.end(), 0);

    return max(dp[u][b][1], dp[u][b][0]);
  }

  int maxProfit(int n, vector<int> &present, vector<int> &future,
                vector<vector<int>> &hierarchy, int budget) {

    P = present;
    F = future;
    adj.assign(n, {});
    dp.assign(n, vector<vector<ll>>(budget + 1, vector<ll>(2, -1)));

    for (auto &edge : hierarchy) {
      adj[edge[0] - 1].push_back(edge[1] - 1);
    }

    return dfs(0, budget, 0, -1);
  }
};
