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

using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vll = vector<ll>;
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
  int N, M, C;
  cin >> N >> M >> C;

  vi moons(N, 0);
  vector<vi> adj(N);

  each(it, moons) cin >> it;

  while (M--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }

  ll ans = 0;

  vector<vll> dp(N, vll(1001, -1));

  dp[0][0] = 0;

  loop(d, 0, 1001, +1) {
    loop(i, 0, N, +1) {
      if (dp[i][d] == -1)
        continue;

      each(c, adj[i]) {
        if (d + 1 < 1001)
          dp[c][d + 1] = max(dp[c][d + 1], dp[i][d] + moons[i]);
      }
    }

    ans = max(ans, dp[0][d] - (ll)C * d * d);
  }

  cout << ans << endl;
}

int main() {
  usaco("time");
  fastIO();
  solve();

  return 0;
}
