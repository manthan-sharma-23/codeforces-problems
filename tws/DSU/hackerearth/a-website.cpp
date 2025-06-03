#include <bits/stdc++.h>
using namespace std;

#define FIO                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);
#define each(x, v) for (auto &x : v)
using ll = long long;

struct DSU {
  vector<int> parent, sz;
  DSU(int n) {
    parent.resize(n);
    sz.resize(n, 1);
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

  bool unite(int x, int y) {
    int xr = find(x), yr = find(y);
    if (xr != yr) {
      if (sz[xr] < sz[yr])
        swap(xr, yr);
      parent[yr] = xr;
      sz[xr] += sz[yr];
      return 1;
    } else {
      return 0;
    }
  }
};

void solve() {
  int n;
  cin >> n;

  vector<pair<string, string>> raw(n);
  unordered_map<string, int> mp;
  int id = 0;
  for (int i = 0; i < n; i++) {
    cin >> raw[i].first >> raw[i].second;
    if (!mp.count(raw[i].first))
      mp[raw[i].first] = id++;
    if (!mp.count(raw[i].second))
      mp[raw[i].second] = id++;
  }

  int total_nodes = id;

  vector<pair<int, int>> edges;
  DSU dsu(total_nodes);

  for (auto &[a, b] : raw) {
    int u = mp[a], v = mp[b];
    edges.emplace_back(u, v);
  }

  int total = 0;
  for (auto [u, v] : edges) {
    if (u == v)
      continue;
    total++;
    if (!dsu.unite(u, v)) {
      total++;
    }
  }

  cout << total << '\n';
}

int main() {
  FIO int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
