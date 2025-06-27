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
  ll dp[65][2][2];

  string toBinary(ll x) {
    if (x == 0)
      return "0";

    string result;
    while (x > 0) {
      result = char('0' + (x % 2)) + result;
      x /= 2;
    }
    return result;
  }

  ll f(int idx, int tight, int last, const string &s) {
    if (idx == s.length())
      return 1;

    int limit = tight ? s[idx] - '0' : 1;

    ll &ans = dp[idx][tight][last];

    if (ans != -1)
      return ans;

    ans = 0;
    for (int b = 0; b <= limit; b++) {
      if (last == 1 && b == 1)
        continue;
      ans += f(idx + 1, tight & (b == limit), b, s);
    }

    return ans;
  }

  int findIntegers(int n) {
    memset(dp, -1, sizeof(dp));
    string bin = toBinary(n);

    return f(0, 1, 0, bin);
  }
};