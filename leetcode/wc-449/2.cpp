#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int m, n;
  bool canPartitionGrid(vector<vector<int>> &grid) {
    m = grid.size(), n = grid[0].size();

    ll totalSum = 0;
    vector<ll> rowSum(m, 0), colSum(n, 0);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        rowSum[i] += grid[i][j];
        colSum[j] += grid[i][j];
        totalSum += grid[i][j];
      }

    ll upperSum = 0;
    for (int i = 0; i < m - 1; ++i) {
      upperSum += rowSum[i];
      ll lowerSum = totalSum - upperSum;
      if (upperSum == lowerSum)
        return true;
    }

    ll leftSum = 0;
    for (int j = 0; j < n - 1; ++j) {
      leftSum += colSum[j];
      ll rightSum = totalSum - leftSum;
      if (leftSum == rightSum)
        return true;
    }

    return false;
  }
};