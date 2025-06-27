#include <bits/stdc++.h>
using namespace std;

class Solution {
  using ll = long long;
  struct Edge {
    int to;
    ll w;
  };
  static const int LOG = 17;

public:
  vector<int> findMedian(int n, vector<vector<int>> &edges,
                         vector<vector<int>> &queries) {
    vector<array<ll, 3>> sabrelonta;
    sabrelonta.reserve(edges.size());
    for (auto &e : edges)
      sabrelonta.push_back({e[0], e[1], e[2]});

    vector<vector<Edge>> g(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      ll w = e[2];
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }

    vector<array<int, LOG>> up(n);
    vector<array<ll, LOG>> wUp(n);
    vector<int> depth(n);
    vector<ll> distRoot(n);

    auto dfs = [&](auto &&self, int v, int p) -> void {
      for (auto [to, w] : g[v]) {
        if (to != p) {
          up[to][0] = v;
          wUp[to][0] = w;
          depth[to] = depth[v] + 1;
          distRoot[to] = distRoot[v] + w;
          self(self, to, v);
        }
      }
    };

    up[0].fill(-1);
    wUp[0].fill(0);
    dfs(dfs, 0, -1);

    for (int k = 1; k < LOG; ++k) {
      for (int v = 0; v < n; ++v) {
        int mid = up[v][k - 1];
        up[v][k] = (mid == -1 ? -1 : up[mid][k - 1]);
        wUp[v][k] = wUp[v][k - 1] + (mid == -1 ? 0 : wUp[mid][k - 1]);
      }
    }

    auto lca = [&](int a, int b) {
      if (depth[a] < depth[b])
        swap(a, b);
      int diff = depth[a] - depth[b];
      for (int k = LOG - 1; k >= 0; --k)
        if (diff & (1 << k))
          a = up[a][k];
      if (a == b)
        return a;
      for (int k = LOG - 1; k >= 0; --k)
        if (up[a][k] != up[b][k]) {
          a = up[a][k];
          b = up[b][k];
        }
      return up[a][0];
    };

    auto firstCrossFrom = [&](int v, ll need) {
      ll acc = 0;
      for (int k = LOG - 1; k >= 0; --k) {
        int nxt = up[v][k];
        if (nxt != -1 && acc + wUp[v][k] < need) {
          acc += wUp[v][k];
          v = nxt;
        }
      }
      return acc >= need ? v : up[v][0];
    };

    auto farthestWithin = [&](int v, ll limit) {
      ll acc = 0;
      for (int k = LOG - 1; k >= 0; --k) {
        int nxt = up[v][k];
        if (nxt != -1 && acc + wUp[v][k] <= limit) {
          acc += wUp[v][k];
          v = nxt;
        }
      }
      return v;
    };

    int q = queries.size();
    vector<int> ans(q);
    for (int i = 0; i < q; ++i) {
      int u = queries[i][0], v = queries[i][1];
      if (u == v) {
        ans[i] = u;
        continue;
      }
      int C = lca(u, v);
      ll tot = distRoot[u] + distRoot[v] - 2 * distRoot[C];
      ll half = (tot + 1) / 2;
      ll toC = distRoot[u] - distRoot[C];
      if (half <= toC)
        ans[i] = firstCrossFrom(u, half);
      else
        ans[i] = farthestWithin(v, tot - half);
    }

    return ans;
  }
};