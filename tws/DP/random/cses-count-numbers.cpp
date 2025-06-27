#include <bits/stdc++.h>
using namespace std;

#define FIO                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);
#define ll long long

ll dp[20][2][11][2];

ll f(int idx, bool tight, int last, bool has0, const string &s) {
  if (idx == (int)s.length())
    return 1;

  if (dp[idx][tight][last + 1][has0] != -1)
    return dp[idx][tight][last + 1][has0];

  int limit = tight ? s[idx] - '0' : 9;
  ll ans = 0;

  for (int d = 0; d <= limit; d++) {
    if (d != last || has0)
      ans += f(idx + 1, tight & (d == limit), d, has0 & (d == 0), s);
  }

  return dp[idx][tight][last + 1][has0] = ans;
}

void solve() {
  ll l, r;
  cin >> l >> r;
  string li = to_string(l - 1), ri = to_string(r);

  memset(dp, -1, sizeof(dp));
  ll ra = f(0, 1, -1, 1, ri);
  memset(dp, -1, sizeof(dp));
  ll la = f(0, 1, -1, 1, li);

  cout << ra - la << '\n';
}

int main() {
  FIO solve();
  return 0;
}
