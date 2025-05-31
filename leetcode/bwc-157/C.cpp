#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxHeight = 0;

  void dfs(int node, int parent, int depth, vector<vector<int>> &adj) {
    maxHeight = max(maxHeight, depth);
    for (int neighbor : adj[node]) {
      if (neighbor != parent) {
        dfs(neighbor, node, depth + 1, adj);
      }
    }
  }

  int assignEdgeWeights(vector<vector<int>> &edges) {
    int n = edges.size() + 1;
    vector<vector<int>> adj(n + 1);
    for (auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    dfs(1, -1, 0, adj);

    return maxHeight;
  }
};
