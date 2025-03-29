#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<pair<int, int>> dp(1 << n, {n + 1, 0});
  dp[0] = {1, 0};

  for (int mask = 0; mask < (1 << n); mask++) {
    for (int bit = 0; bit < n; bit++) {
      if (mask & (1 << bit))
        continue;

      int newMask = mask | (1 << bit);
      auto [numRides, wt] = dp[mask];

      if (wt + a[bit] <= x) {
        dp[newMask] = min(dp[newMask], {numRides, wt + a[bit]});
      } else {
        dp[newMask] = min(dp[newMask], {numRides + 1, a[bit]});
      }
    }
  }

  cout << dp[(1 << n) - 1].first << endl;
}

int main() {
  fastIO();
  solve();
  return 0;
}
