#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n;
  vector<int> Score;
  vector<vector<int>> adj;
  vector<vector<int>> toThisNode;
  vector<int> indegree, outDegree;
  vector<int> preRequisite;
  vector<int> dp;

  int dfs1(int node) {
    int requisite = 0;
    for (int child : toThisNode[node]) {
      requisite |= dfs1(child);
    }
    preRequisite[node] = requisite;
    return (requisite | (1 << node));
  }

  int countBits(int mask) {
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i))
        count++;
    }

    return count;
  }

  int dfs2(int mask) {
    if (dp[mask] != -1)
      return dp[mask];

    int pos = countBits(mask) + 1;

    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
      if (!(mask & (1 << i)) && ((mask & preRequisite[i]) == preRequisite[i])) {
        maxProfit = max(maxProfit, (pos * Score[i]) + dfs2(mask | (1 << i)));
      }
    }
    return dp[mask] = maxProfit;
  }

  int maxProfit(int n, vector<vector<int>> &edges, vector<int> &score) {
    this->n = n;
    Score = score;
    outDegree.assign(n, 0);
    indegree.assign(n, 0);
    toThisNode.assign(n, {});
    adj.assign(n, {});

    for (auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];
      adj[u].push_back(v);
      toThisNode[v].push_back(u);
      indegree[v]++;
      outDegree[u]++;
    }

    preRequisite.assign(n, 0);
    dp.assign(1 << n, -1);
    for (int i = 0; i < n; i++) {
      if (outDegree[i] == 0) {
        dfs1(i);
      }
    }

    return dfs2(0);
  }
};
