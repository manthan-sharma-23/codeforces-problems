#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define each(x, a) for (auto &x : a)
const int INF = 1e9;

vector<vector<vector<ll>>> dp;

ll f(int i, int sm, int lg, const vi &a, const int n) {
  // Normalize sm and lg for DP array index (you can also use maps for large
  // range)
  if (dp[i][sm][lg] != -1)
    return dp[i][sm][lg];

  if (i == n)
    return 0;

  ll ans = f(i + 1, sm, lg, a, n);

  if (a[i] <= sm || a[i] >= lg)
    ans = max(ans, (ll)a[i] + f(i + 1, min(sm, a[i]), max(lg, a[i]), a, n));

  return dp[i][sm][lg] = ans;
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  each(it, a) cin >> it;

  int max_val = *max_element(a.begin(), a.end());

  // Initialize dp with -1, size depends on max value a[i] can take
  dp.assign(n + 1,
            vector<vector<ll>>(max_val + 1, vector<ll>(max_val + 1, -1)));

  // Start with sm = INF, lg = 0 or other appropriate bounds
  cout << f(0, max_val, 0, a, n) << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}