
#include <bits/stdc++.h>

using namespace std;

class Solution {
  typedef long long ll;

public:
  long long calculateScore(vector<string> &instructions, vector<int> &values) {
    int n = instructions.size();

    ll score = 0LL;

    vector<bool> vis(n, false);

    int i = 0;
    while (i >= 0 && i < n && !vis[i]) {
      vis[i] = true;
      if (instructions[i] == "add") {
        score += values[i];
        i++;
      } else {
        i += values[i];
      }
    }

    return score;
  }
};