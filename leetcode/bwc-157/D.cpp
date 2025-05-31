#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int n, LOG;
  vector<vector<int>> adj, up;
  vector<int> depth;
  const int MOD = 1e9 + 7;

  void dfs(int v, int p) {
    up[v][0] = p;
    for (int i = 1; i <= LOG; i++) {
      if (up[v][i - 1] == -1)
        up[v][i] = -1;
      else
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (auto &to : adj[v]) {
      if (to != p) {
        depth[to] = depth[v] + 1;
        dfs(to, v);
      }
    }
  }

  int lca(int u, int v) {
    if (depth[u] < depth[v])
      swap(u, v);
    for (int i = LOG; i >= 0; i--) {
      if (up[u][i] != -1 && depth[up[u][i]] >= depth[v]) {
        u = up[u][i];
      }
    }
    if (u == v)
      return u;
    for (int i = LOG; i >= 0; i--) {
      if (up[u][i] != -1 && up[u][i] != up[v][i]) {
        u = up[u][i];
        v = up[v][i];
      }
    }
    return up[u][0];
  }

  int modPow(int base, int exp, int mod) {
    long long res = 1, cur = base;
    while (exp > 0) {
      if (exp & 1)
        res = (res * cur) % mod;
      cur = (cur * cur) % mod;
      exp >>= 1;
    }
    return (int)res;
  }

  vector<int> assignEdgeWeights(vector<vector<int>> &edges,
                                vector<vector<int>> &queries) {
    n = (int)edges.size() + 1;
    LOG = 0;
    while ((1 << LOG) <= n)
      LOG++;

    adj.assign(n + 1, vector<int>());
    up.assign(n + 1, vector<int>(LOG + 1, -1));
    depth.assign(n + 1, 0);

    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(1, -1);

    vector<int> res;
    for (auto &q : queries) {
      int u = q[0], v = q[1];
      int ancestor = lca(u, v);
      int dist = depth[u] + depth[v] - 2 * depth[ancestor];
      int val = (dist == 0) ? 0 : modPow(2, dist - 1, MOD);
      res.push_back(val);
    }
    return res;
  }
};