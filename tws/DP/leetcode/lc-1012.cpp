#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define F first
#define S second
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2>
#define hash_set(T) unordered_set<T>
#define loop(i, a, b, step) for (int i = (a); i < (b); i += step)
#define asc(v) sort((v).begin(), (v).end())
#define dsc(v) sort((v).rbegin(), (v).rend())
#define ll long long
#define vi vector<int>
#define vll vector<ll>

class Solution {
public:
  const static ll maxMask = (1 << 11) + 1;
  ll dp[12][2][2][maxMask][2];

  ll f(int idx, bool tight, bool rep, ll mask, bool all0s, const string &s) {
    if (idx == s.length())
      return !all0s && rep;

    ll &ans = dp[idx][tight][rep][mask][all0s];

    if (ans != -1)
      return ans;

    int limit = tight ? s[idx] - '0' : 9;

    ans = 0;

    for (int d = 0; d <= limit; d++) {
      if (all0s && d == 0) {
        ans += f(idx + 1, tight && (d == limit), rep, mask, all0s, s);
      } else {
        bool n_rep = rep || (mask & (1 << d));
        ll n_mask = mask | (1 << d);
        ans += f(idx + 1, tight && (d == limit), n_rep, n_mask, false, s);
      }
    }

    return ans;
  }

  int numDupDigitsAtMostN(int n) {
    memset(dp, -1, sizeof(dp));
    string s = to_string(n);
    return f(0, 1, 0, 0LL, 1, s);
  }
};