#include <bits/stdc++.h>
// manthan's code
using namespace std;
#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2, custom_hash>
#define hash_set(T) unordered_set<T>
#define loop(i, a, b, step) for (int i = (a); i < (b); i += step)
#define asc(v) sort((v).begin(), (v).end())
#define dsc(v) sort((v).rbegin(), (v).rend())

using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vll = vector<ll>;
using vi = vector<int>;

const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void usaco(string name = "h") {

  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}

void solve() {
  int s, n;
  cin >> s >> n;

  vector<pair<int, pair<int, int>>> items;

  for (int i = 0; i < n; i++) {
    int v, w, c;
    cin >> v >> w >> c;

    // Break c into powers of 2
    for (int k = 1; k <= c; k <<= 1) {
      items.push_back({v * k, {w * k, 1}});
      c -= k;
    }
    if (c > 0) {
      items.push_back({v * c, {w * c, 1}});
    }
  }

  // Now it's a 0-1 knapsack
  vector<ll> dp(s + 1, 0);

  for (auto &[val, wc] : items) {
    auto [wt, dummy] = wc;
    for (int j = s; j >= wt; j--) {
      dp[j] = max(dp[j], dp[j - wt] + val);
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
  // usaco();
  fastIO();
  solve();

  return 0;
}
