#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
  int maxFreqSum(string s) {
    unordered_map<char, int> fv, fc;

    for (auto ch : s) {
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        fv[ch]++;
      else
        fc[ch]++;
    }

    int maxv = 0, maxc = 0;

    for (auto it : fv) {
      maxv = max(maxv, it.second);
    }

    for (auto it : fc) {
      maxc = max(maxc, it.second);
    }

    return maxv + maxc;
  }
};