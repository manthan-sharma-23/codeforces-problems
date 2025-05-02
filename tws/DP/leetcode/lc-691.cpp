#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> T;
  int minStickers(vector<string> &stickers, string target) {
    int n = stickers.size(), t = target.size();

    vector<vector<int>> store(n + 1, vector<int>(26, 0));

    for (int i = 1; i <= n; i++) {
      for (auto &ch : stickers[i]) {
        store[i - 1][ch - 'a']++;
      }
    }

    T.resize(26, 0);

    vector<vector<int>> dp(n + 1, vector<int>(t + 1, INT_MAX));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = 0;
    }

    for (int j = 1; j <= t; j++) {
      T[target[j - 1] - 'a']++;
      for (int i = 1; i <= n; i++) {
        bool isValid = false;

        

      }
    }
  }
};