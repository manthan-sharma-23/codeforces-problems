#include <bits/stdc++.h>
using namespace std;

#define min_heap(T) priority_queue<T, vector<T>, greater<T>>

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

  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    int n = s.length();

    DSU dsu(n);

    for (auto p : pairs) {
      dsu.unite(p[0], p[1]);
    }

    vector<int> groups(n);
    int g = 0;
    for (int i = 0; i < n; i++) {
      int p = dsu.find(i);
      if (p == i) {
        groups[i] = g++;
      }
    }
    vector<min_heap(char)> vpq(g, min_heap(char)());
    for (int i = 0; i < n; i++) {
      int p = dsu.find(i);
      vpq[groups[p]].push(s[i] - 'a');
    }

    string res;

    for (int i = 0; i < n; i++) {
      int p = dsu.find(i);

      res.push_back(vpq[groups[p]].top());
      vpq[groups[p]].pop();
    }

    return res;
  }
};