#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  using ll = long long;
  vector<vector<pair<int, int>>> adj;
  int K, T;
  int ans = -1;
  vector<vector<unordered_set<int>>> dp;

  void dfs(int u, int steps, int W) {
    if (W >= T)
      return;
    if (dp[u][steps].count(W))
      return;

    dp[u][steps].insert(W);

    if (steps == 0) {
      ans = max(ans, W);
      return;
    }

    for (auto &[v, w] : adj[u]) {
      dfs(v, steps - 1, W + w);
    }
  }

  int maxWeight(int n, vector<vector<int>> &edges, int k, int t) {
    adj.assign(n, {});
    K = k, T = t;
    dp.assign(n, vector<unordered_set<int>>(k + 1));

    for (auto &e : edges) {
      int u = e[0], v = e[1], w = e[2];
      adj[u].emplace_back(v, w);
    }

    for (int root = 0; root < n; ++root) {
      dfs(root, k, 0);
    }

    return ans;
  }
};