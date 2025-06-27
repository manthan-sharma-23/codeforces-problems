#include <bits/stdc++.h>
#include <cstring>
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
  vector<vector<vector<vector<vll>>>> dp;
  ll mod_expo(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
      if (exp % 2 == 1)
        result = (result * base) % mod;
      base = (base * base) % mod;
      exp /= 2;
    }
    return result;
  }

  ll f(int idx, bool tight, int diff, int rem, bool all0, const string &s,
       int k) {
    if (idx == s.size())
      return (!all0 && diff == 0 && rem == 0);

    ll &res = dp[idx][tight][diff + 11][rem][all0];
    if (res != -1)
      return res;

    res = 0;
    int limit = tight ? s[idx] - '0' : 9;
    ll place = mod_expo(10, s.size() - 1 - idx, k);

    for (int d = 0; d <= limit; d++) {
      bool newAll0 = all0 && (d == 0);
      int newDiff = diff;
      if (!newAll0) {
        newDiff += (d % 2 == 0) ? 1 : -1;
      }

      int remaining = s.size() - idx - 1;
      if (abs(newDiff) > remaining)
        continue;

      int newRem = (rem + (d * place) % k) % k;
      res += f(idx + 1, tight && (d == limit), newDiff, newRem, newAll0, s, k);
    }

    return res;
  }

  int numberOfBeautifulIntegers(int low, int high, int k) {
    auto solve = [&](int num) {
      string s = to_string(num);
      dp.assign(s.size(),
                vector<vector<vector<vll>>>(
                    2, vector<vector<vll>>(23, vector<vll>(k, vll(2, -1)))));
      return f(0, 1, 0, 0, 1, s, k);
    };

    return solve(high) - solve(low - 1);
  }
};
