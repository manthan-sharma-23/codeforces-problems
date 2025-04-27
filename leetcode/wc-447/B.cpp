#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> adj;
  vector<int> groups;

  void dfs(int node, const int &group) {
    groups[node] = group;

    for (auto child : adj[node]) {
      if (groups[child] == -1)
        dfs(child, group);
    }
  }

  vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
                                    vector<vector<int>> &queries) {

    adj.assign(n, {});
    groups.assign(n, -1);

    for (int i = 0; i < n - 1; i++) {
      if (abs(nums[i + 1] - nums[i]) <= maxDiff) {
        adj[nums[i]].push_back(nums[i + 1]);
        adj[nums[i + 1]].push_back(nums[i]);
      }
    }

    int g = 1;

    for (int i = 0; i < n; i++) {
      if (groups[i] == -1) {
        dfs(i, g);
        g++;
      }
    }

    vector<bool> res;

    for (auto q : queries) {
      int u = q[0], v = q[1];
      if (groups[u] == groups[v])
        res.push_back(true);
      else
        res.push_back(false);
    }

    return res;
  }
};