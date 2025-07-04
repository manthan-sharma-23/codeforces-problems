#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct DSU {
  int n;
  vector<int> parent, rank;
  DSU(int _n) : n(_n), parent(n), rank(n, 0) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return false;
    if (rank[a] < rank[b])
      swap(a, b);
    parent[b] = a;
    if (rank[a] == rank[b])
      rank[a]++;
    return true;
  }
};

bool can(ll s, int n, const vector<vector<int>> &edges, int k) {
  DSU dsu(n);
  int used_edges = 0;
  int upgrades = 0;
  for (auto &e : edges) {
    int u = e[0], v = e[1];
    ll strength = e[2];
    int must = e[3];
    if (must == 1) {
      if (strength < s)
        return false;
      if (!dsu.unite(u, v))
        return false;
      used_edges++;
    }
  }
  vector<pair<int, int>> zeroCost;
  vector<pair<int, int>> oneCost;
  for (auto &e : edges) {
    int u = e[0], v = e[1];
    ll strength = e[2];
    int must = e[3];
    if (must == 0) {
      if (strength >= s)
        zeroCost.emplace_back(u, v);
      else if (strength * 2 >= s)
        oneCost.emplace_back(u, v);
    }
  }
  for (auto &p : zeroCost) {
    if (used_edges == n - 1)
      break;
    if (dsu.unite(p.first, p.second))
      used_edges++;
  }
  for (auto &p : oneCost) {
    if (used_edges == n - 1)
      break;
    if (dsu.unite(p.first, p.second)) {
      used_edges++;
      upgrades++;
      if (upgrades > k)
        return false;
    }
  }
  return used_edges == n - 1;
}

class Solution {
public:
  int maxStability(int n, vector<vector<int>> &edges, int k) {

    ll hi = 0;
    for (auto &e : edges) {
      hi = max(hi, (ll)e[2]);
      if (e[3] == 0)
        hi = max(hi, (ll)e[2] * 2);
    }
    ll lo = 0, ans = -1;

    while (lo <= hi) {
      ll mid = lo + (hi - lo) / 2;
      if (can(mid, n, edges, k)) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return (int)ans;
  }
};
