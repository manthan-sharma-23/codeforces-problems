#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
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

  int removeStones(vector<vector<int>> &stones) {
    
  }
};