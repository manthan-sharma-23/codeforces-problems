#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define F first
#define S second
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2>
#define hash_set(T) unordered_set<T>
#define loop(i, a, b, step) for (int i = (a); i < (b); i += step)
#define asc(v) sort((v).begin(), (v).end())
#define dsc(v) sort((v).rbegin(), (v).rend())
#define ll long long
#define vi vector<int>
#define vll vector<ll>

struct DSU {

  vi parent, size;

  DSU(int n) {
    parent.assign(n, -1);
    size.assign(n, 1);
  }

  int find(int u) {
    if (parent[u] == -1)
      return u;
    else
      return parent[u] = find(parent[u]);
  }

  bool same(int u, int v) { return find(u) == find(v); }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
      return 0;

    if (size[v] > size[u])
      swap(u, v);

    size[u] += size[v];
    parent[v] = u;
    return 1;
  }

  int components() {
    int count = 0;
    for (int i = 0; i < parent.size(); ++i) {
      if (find(i) == i)
        count++;
    }
    return count;
  }
};

class Solution {
public:
  int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {

    DSU a(n), b(n);
    int totalEdges = 0;

    dsc(edges);

    for (auto e : edges) {
      int type = e[0], u = e[1], v = e[2];
      u--, v--;

      if (type == 3) {
        bool ua = a.unite(u, v);
        bool ub = b.unite(u, v);
        if (ua || ub)
          totalEdges++;
      } else if (type == 2) {
        if (!b.same(u, v)) {
          b.unite(u, v);
          totalEdges++;
        }
      } else {
        if (!a.same(u, v)) {
          a.unite(u, v);
          totalEdges++;
        }
      }
    }

    if (a.components() > 1 || b.components() > 1)
      return -1;

    return edges.size() - totalEdges;
  }
};