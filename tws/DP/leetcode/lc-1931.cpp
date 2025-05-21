#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int m, n;
  vector<vector<int>> validStates;
  vector<int> stateList;
  unordered_map<int, vector<int>> nextStateMap;
  unordered_map<int, vector<int>> stateToColors;
  unordered_map<int, int> dp[1005];

  void generateStates(int row, int currState, vector<int> &colors) {
    if (row == m) {
      stateList.push_back(currState);
      stateToColors[currState] = colors;
      return;
    }

    for (int color = 1; color <= 3; color++) {
      if (row > 0 && colors[row - 1] == color)
        continue;
      colors[row] = color;
      generateStates(row + 1, currState * 10 + color, colors);
    }
  }

  bool isCompatible(int s1, int s2) {
    const vector<int> &c1 = stateToColors[s1];
    const vector<int> &c2 = stateToColors[s2];
    for (int i = 0; i < m; i++) {
      if (c1[i] == c2[i])
        return false;
    }
    return true;
  }

  int dfs(int col, int prevState) {
    if (col == n)
      return 1;
    if (dp[col].count(prevState))
      return dp[col][prevState];

    int res = 0;
    for (int nextState : nextStateMap[prevState]) {
      res = (res + dfs(col + 1, nextState)) % 1000000007;
    }

    return dp[col][prevState] = res;
  }

  int colorTheGrid(int m, int n) {
    this->m = m;
    this->n = n;

    vector<int> colors(m);
    generateStates(0, 0, colors);

    for (int s1 : stateList) {
      for (int s2 : stateList) {
        if (isCompatible(s1, s2)) {
          nextStateMap[s1].push_back(s2);
        }
      }
    }

    int result = 0;
    for (int state : stateList) {
      result = (result + dfs(1, state)) % 1000000007;
    }

    return result;
  }
};
