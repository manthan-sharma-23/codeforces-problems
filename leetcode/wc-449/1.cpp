#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minDeletion(string s, int k) {
    unordered_map<int, int> mp;

    for (auto ch : s) {
      mp[ch]++;
    }
    set<pair<int, int>> st;

    for (auto it : mp) {
      st.insert({it.second, it.first});
    }

    int ans = 0;

    while (st.size() > k) {
      auto top = st.begin();
      ans += top->first;

      st.erase(top);
    }

    return ans;
  }
};