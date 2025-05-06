
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n;
  using ll = long long;
  vector<int> memo;
  const ll p = 37;
  const int MOD = 1e9 + 7;

  vector<vector<int>> hash;

  void computeHash(string &s) {

    for (int i = 0; i < n; i++) {
      ll pwr = 1LL;
      ll pref = 0LL;
      for (int j = i; j < n; j++) {
        pref = (pref + (pwr * s[j - 1])) % MOD;

        hash[i][j] = pref;
        pwr = (pwr * p) % MOD;
      }
    }
  }

  int checkHash(int i, int l) { return hash[i][i + l - 1]; }

  int f(int i, const string &s) {

    if (i >= n) {
      return 0;
    }
    if (memo[i] != -1)
      return memo[i];
    int res = 1;
    for (int len = 2; len <= n - i; len += 2) {
      if (checkHash(i, len / 2) == checkHash(i + len / 2, len / 2)) {
        res = max(res, 1 + f(i + len, s));
      }
    }

    return memo[i] = res;
  }

  int deleteString(string s) {
    n = s.length();
    memo.assign(n, -1);
    hash.assign(n, vector<int>(n, 0));

    return f(0, s);
  }
};