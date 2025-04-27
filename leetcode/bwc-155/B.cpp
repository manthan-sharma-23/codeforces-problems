#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
  vector<int> res;
  vector<vector<pair<int, ll>>> adj;
  const static int MOD = 1e9 + 7;

  void dfs(int node, ll power) {
    res[node] = power % MOD;

    for (auto &[child, wt] : adj[node]) {
      dfs(child, (power % MOD * wt % MOD) % MOD);
    }
  }

  vector<int> baseUnitConversions(vector<vector<int>> &conversions) {
    int n = conversions.size();
    adj.assign(n + 1, {});
    res.assign(n + 1, 1);

    for (auto edge : conversions) {
      adj[edge[0]].push_back({edge[1], edge[2]});
    }

    dfs(0, 1LL);

    return res;
  }
};