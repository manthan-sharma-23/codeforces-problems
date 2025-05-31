#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> kmp(string &w, string &patt) {
    int n = w.size(), m = patt.size();
    vector<int> lps(m, 0), res;

    for (int i = 1, len = 0; i < m;) {
      if (patt[i] == patt[len]) {
        lps[i++] = ++len;
      } else {
        if (len != 0)
          len = lps[len - 1];
        else
          lps[i++] = 0;
      }
    }

    for (int i = 0, j = 0; i < n;) {
      if (w[i] == patt[j]) {
        ++i, ++j;
      }
      if (j == m) {
        res.push_back(i - j);
        j = lps[j - 1];
      } else if (i < n && w[i] != patt[j]) {
        if (j != 0)
          j = lps[j - 1];
        else
          ++i;
      }
    }

    sort(res.begin(), res.end());

    return res;
  }

  vector<int> beautifulIndices(string s, string a, string b, int k) {
    auto va = kmp(s, a);
    auto vb = kmp(s, b);
    vector<int> rs;

    for (auto i : va) {
      auto it = lower_bound(vb.begin(), vb.end(), i);

      if (it != vb.end() && abs(i - *it) <= k) {
        rs.push_back(i);
        continue;
      }

      if (it != vb.begin()) {
        --it;
        if (abs(i - *it) <= k) {
          rs.push_back(i);
        }
      }
    }

    return rs;
  }
};