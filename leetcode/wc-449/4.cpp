#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  bool canPartitionGrid(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    ll totalSum = 0;
    vector<ll> rowSum(m, 0), colSum(n, 0);
    unordered_map<int, vector<pair<int, int>>> hs;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        rowSum[i] += grid[i][j];
        colSum[j] += grid[i][j];
        totalSum += grid[i][j];
        hs[grid[i][j]].emplace_back(i, j);
      }

    ll upperSum = 0;
    for (int i = 0; i < m - 1; ++i) {
      upperSum += rowSum[i];
      ll lowerSum = totalSum - upperSum;
      if (upperSum == lowerSum)
        return true;

      ll diff = abs(upperSum - lowerSum);
      for (auto [x, y] : hs[diff]) {
        if (upperSum > lowerSum && x < i + 1) {
          int rowsInUpper = i + 1;

          if (n == 1 && x != 0 && x != i)
            continue;

          if (rowsInUpper > 1 || y == 0 || y == n - 1)
            return true;
        }

        if (lowerSum > upperSum && x >= i + 1) {
          int rowsInLower = m - (i + 1);

          if (n == 1 && x != i + 1 && x != m - 1)
            continue;

          if (rowsInLower > 1 || y == 0 || y == n - 1)
            return true;
        }
      }
    }

    if (n > 1) {
      ll leftSum = 0;
      for (int j = 0; j < n - 1; ++j) {
        leftSum += colSum[j];
        ll rightSum = totalSum - leftSum;
        if (leftSum == rightSum)
          return true;

        ll diff = abs(leftSum - rightSum);
        for (auto [x, y] : hs[diff]) {
          if (leftSum > rightSum && y < j + 1) {
            int colsInLeft = j + 1;

            if (colsInLeft > 1 || x == 0 || x == m - 1)
              return true;
          }
          if (rightSum > leftSum && y >= j + 1) {
            int colsInRight = n - (j + 1);

            if (colsInRight > 1 || x == 0 || x == m - 1)
              return true;
          }
        }
      }
    }

    return false;
  }
};
