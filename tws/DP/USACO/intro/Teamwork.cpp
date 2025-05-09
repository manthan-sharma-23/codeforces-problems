#include <bits/stdc++.h>
using namespace std;

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define loop(i, a, b, step) for (int i = (a); i < (b); i += step)
#define revloop(i, a, b, step) for (int i = (a); i >= (b); i += step)

using ll = long long;
using vi = vector<int>;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void usaco(string name = "h") {

  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}

void solve() {
  int n, k;
  cin >> n >> k;

  vi c(n);
  each(it, c) cin >> it;

  vector<ll> dp(n + 1, 0);

  loop(i, 1, n + 1, 1) {
    int max_skill = 0;

    revloop(j, i - 1, max(i - k, 0), -1) {
      max_skill = max(max_skill, c[j]);
      dp[i] = max(dp[i], dp[j] + max_skill * (i - j));
    }
  }

  cout << dp[n] << endl;
}

int main() {
  usaco("teamwork");
  fastIO();
  solve();
  return 0;
}
