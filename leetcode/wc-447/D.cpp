#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> adj;
  vector<int> groups;

  vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
                                   vector<vector<int>> &queries) {
    sort(nums.begin(), nums.end());

    adj.assign(n, {});
    groups.assign(n, -1);

    for (int i = 0; i < n - 1; i++) {
      if (abs(nums[i + 1] - nums[i]) <= maxDiff) {
        adj[nums[i]].push_back(nums[i + 1]);
        adj[nums[i + 1]].push_back(nums[i]);
      }
    }
  }
};