#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> findMatrix(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (const int it : nums) {
      mp[it]++;
    }

    vector<vector<int>> grid;

    while (!mp.empty()) {
      vector<int> row;
      for (const auto &it : mp) {
        row.push_back(it.first);
        mp[it.first]--;
        if (mp[it.first] == 0) {
          mp.erase(it.first);
        }
      }
      grid.push_back(row);
    }

    return grid;
  }
};