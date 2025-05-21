#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  using ll = long long;
  const int MOD = 1e9 + 7;
  const int BASE = 26;

  string computeRabinKarp(const string &s, int len) {
    int n = s.size();
    if (len == 0)
      return "";

    ll hash = 0;
    ll power = 1;
    for (int i = 0; i < len; ++i) {
      hash = (hash * BASE + (s[i] - 'a' + 1)) % MOD;
      if (i < len - 1)
        power = (power * BASE) % MOD;
    }

    unordered_map<ll, vector<int>> hashMap;
    hashMap[hash].push_back(0);

    for (int i = 1; i + len <= n; ++i) {
      hash = (hash - (ll)(s[i - 1] - 'a' + 1) * power % MOD + MOD) % MOD;
      hash = (hash * BASE + (s[i + len - 1] - 'a' + 1)) % MOD;

      if (hashMap.count(hash)) {
        for (int startIdx : hashMap[hash]) {
          if (s.substr(startIdx, len) == s.substr(i, len)) {
            return s.substr(i, len);
          }
        }
      }

      hashMap[hash].push_back(i);
    }

    return "";
  }

  string longestDupSubstring(string s) {
    int n = s.size();
    int low = 1, high = n - 1;
    string result = "";

    while (low <= high) {
      int mid = low + (high - low) / 2;
      string dup = computeRabinKarp(s, mid);
      if (!dup.empty()) {
        result = dup;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return result;
  }
};
