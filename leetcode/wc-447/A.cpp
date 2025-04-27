#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countCoveredBuildings(int n, vector<vector<int>> &buildings) {

    vector<pair<int, int>> rows(n, {n, n}), cols(n, {n, n});

    for (auto build : buildings) {
      int x = build[0], y = build[1];

      rows[y].first = min(x, rows[y].first);
      rows[y].second = max(x, rows[y].second);

      cols[x].first = min(x, cols[x].first);
      cols[x].second = min(x, cols[x].second);
    }
  }
};