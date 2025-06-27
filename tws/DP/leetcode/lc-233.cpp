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
  vector<vector<vi>> dp;

  ll solve(int idx, bool tight, int cnt1, const string &r) {
    if (idx == r.size()) {
      return cnt1;
    }

    if (dp[idx][tight][cnt1] != -1)
      return dp[idx][tight][cnt1];

    int limit = tight ? r[idx] - '0' : 9;
    ll ans = 0;
    for (int i = 0; i <= limit; i++) {

      int newCnt = cnt1 + (i == 1);
      ans += solve(idx + 1, (tight & (i == limit)), newCnt, r);
    }

    return dp[idx][tight][cnt1] = ans;
  }

  int countDigitOne(ll n) {
    dp.assign(20, vector<vi>(2, vi(20, -1)));

    string ri = to_string(n);

    return solve(0, 1, 0, ri);
  }
};