#include <bits/stdc++.h>
#include <cstring>
// manthan's code
using namespace std;
#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define FIO                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2>
#define hash_set(T) unordered_set<T>
#define loop(i, a, b, step) for (int i = (a); i < (b); i += step)
#define asc(v) sort((v).begin(), (v).end())
#define dsc(v) sort((v).rbegin(), (v).rend())
#define MOD 1000000007
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define vll vector<ll>
#define vi vector<int>

ll dp[20][2][5];

ll f(int idx, bool tight, int cnt, const string &s) {
  if (cnt > 3)
    return 0LL;
  if (idx == s.length())
    return 1;

  if (dp[idx][tight][cnt] != -1)
    return dp[idx][tight][cnt];

  ll ans = 0;

  int limit = tight ? s[idx] - '0' : 9;

  for (int d = 0; d <= limit; d++) {
    if (cnt < 3) {
      ans += f(idx + 1, (tight & (d == limit)), cnt + (d != 0), s);
    } else if (d == 0) {
      ans += f(idx + 1, (tight & (d == limit)), cnt, s);
    }
  }

  return dp[idx][tight][cnt] = ans;
}

void solve() {
  ll l, r;
  cin >> l >> r;
  string li = to_string(l - 1), ri = to_string(r);

  memset(dp, -1LL, sizeof(dp));
  ll ra = f(0, 1, 0, ri);
  memset(dp, -1LL, sizeof(dp));
  ll la = f(0, 1, 0, li);

  cout << ra - la << endl;
}

int main() {
  // usaco();
  FIO tc solve();

  return 0;
}
