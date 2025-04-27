#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string findCommonResponse(vector<vector<string>> &responses) {

    map<string, int> map;

    for (auto row : responses) {
      unordered_set<string> dict;
      for (string &s : row) {
        dict.insert(s);
      }

      for (auto &it : dict)
        map[it]++;
    }

    int ans = 0;
    string modResp;

    for (auto &it : map) {
      if (it.second > ans) {
        ans = it.second;
        modResp = it.first;
      }
    }

    return modResp;
  }
};