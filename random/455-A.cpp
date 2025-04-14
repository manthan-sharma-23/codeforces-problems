#include <bits/stdc++.h>
using namespace std;

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)

typedef long long ll;
const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  unordered_map<int, int> freq;
  for (int i = 0; i < n; i++) {
    freq[a[i]]++;
  }

  vector<pair<int, ll>> value;
  for (auto &entry : freq) {
    value.push_back({entry.first, entry.first * entry.second});
  }

  sort(value.begin(), value.end());

  int m = value.size();
  vector<ll> dp(m, 0);

  dp[0] = value[0].second;
  for (int i = 1; i < m; i++) {
    ll take = value[i].second;
    if (value[i].first == value[i - 1].first + 1) {
      take += (i >= 2) ? dp[i - 2] : 0;
    } else {
      take += dp[i - 1];
    }
    dp[i] = max(dp[i - 1], take);
  }

  cout << dp[m - 1] << endl;
}

int main() {
  fastIO();
  solve();
  return 0;
}
