#include <bits/stdc++.h>

using namespace std;

struct DSU_rank {
  vector<int> parent, rank;

  DSU_rank(int n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    rank.assign(n, 0);
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    } else
      return parent[x] = find(parent[x]);
  }

  void unite(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);

    if (rank[rootx] < rank[rooty])
      swap(rootx, rooty);

    if (rank[rootx] == rank[rooty])
      rank[rootx]++;

    parent[rooty] = rootx;
  }
};

// by size
struct DSU {
  vector<int> parent, size;

  DSU(int n) {
    parent.resize(n);

    iota(parent.begin(), parent.end(), 0);
    size.assign(n, 1);
  }

  int find(int x) {
    if (parent[x] == x)
      return x;
    else
      return parent[x] = find(parent[x]);
  }

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
      return 0;

    if (size[x] < size[y])
      swap(x, y);

    size[x] += size[y];
    parent[y] = x;

    return 1;
  }

  int size_(int x) { return size[find(x)]; }
};

// weighted union find


