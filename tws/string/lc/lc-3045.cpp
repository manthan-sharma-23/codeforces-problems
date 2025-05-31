#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  using ll = long long;
  string longestPrefixSuffix(const string &s) {
    int n = s.length();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; ++i) {
      int j = pi[i - 1];
      while (j > 0 && s[i] != s[j])
        j = pi[j - 1];
      if (s[i] == s[j])
        ++j;
      pi[i] = j;
    }

    return s.substr(0, pi[n - 1]);
  }
  long long countPrefixSuffixPairs(vector<string> &words) {
    int n = words.size();

    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++)
      mp[words[i]] = 0;

    ll res = 0LL;

    for (int i = 0; i < n; i++) {
      string z = longestPrefixSuffix(words[i]);
      res += (mp[z]);

      mp[words[i]]++;
    }

    return res;
  }
};