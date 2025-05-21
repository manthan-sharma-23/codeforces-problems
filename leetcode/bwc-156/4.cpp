#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
  using ll = long long;
  vector<vector<int>> adj;
  vector<int> val;
  int n;

  const int _INF = INT_MIN;

  vector<vector<vector<ll>>> dp;

  ll dfs(int node, int multiplier, int step, int parent, const int &k) {

    ll res = _INF;

    if (dp[node][step][multiplier] != _INF) {
      return dp[node][step][multiplier];
    }

    if (adj[node].size() == 1 && parent != -1) {
      res = max(res, val[node] * 1LL * multiplier);
      if (step >= k) {
        res = max(res, val[node] * -1LL * multiplier);
      }
    } else {
      for (const int &child : adj[node]) {
        if (child == parent)
          continue;

        res = max(res, val[node] * 1LL * multiplier +
                           dfs(child, multiplier, min(k, step + 1), node, k));

        if (step >= k) {
          res = max(res, val[node] * -1LL * multiplier +
                             dfs(child, -multiplier, 1, node, k));
        }
      }
    }

    return dp[node][step][multiplier] = res;
  }

public:
  long long subtreeInversionSum(vector<vector<int>> &edges, vector<int> &nums,
                                int k) {
    n = nums.size();
    adj.assign(n, {});
    val = nums;
    dp.clear();

    dp.assign(n + 1, vector<vector<ll>>(k + 1, vector<ll>(2, _INF)));

    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    return dfs(0, 1, k, -1, k);
  }
};
