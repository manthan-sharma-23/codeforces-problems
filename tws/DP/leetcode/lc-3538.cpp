#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int recur(int prevPos, int k, int currTime, int n, vector<int> &position,
            vector<int> &time, vector<vector<vector<int>>> &dp) {
    if (prevPos == n - 1) {
      return (k > 0 ? INT_MAX : 0);
    }

    if (dp[prevPos][k][currTime] != -1) {
      return dp[prevPos][k][currTime];
    }

    int ans = INT_MAX;

    int res = recur(prevPos + 1, k, time[prevPos + 1], n, position, time, dp);
    if (res != INT_MAX) {
      ans = min(ans,
                (position[prevPos + 1] - position[prevPos]) * currTime + res);
    }

    if (k > 0) {
      int timeSum = time[prevPos + 1], operations = 0;
      for (int nextIdx = prevPos + 2; nextIdx <= min(n - 1, prevPos + k + 1);
           nextIdx++) {
        timeSum += time[nextIdx];
        operations++;

        int res =
            recur(nextIdx, k - operations, timeSum, n, position, time, dp);
        if (res != INT_MAX) {
          ans = min(ans,
                    (position[nextIdx] - position[prevPos]) * currTime + res);
        }
      }
    }

    dp[prevPos][k][currTime] = ans;

    return ans;
  }

  int minTravelTime(int l, int n, int k, vector<int> &position,
                    vector<int> &time) {
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(k + 1, vector<int>(101, -1)));
    return recur(0, k, time[0], n, position, time, dp);
  }
};