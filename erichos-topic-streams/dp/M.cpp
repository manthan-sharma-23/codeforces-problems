#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
using ll = long long;

// const int INF = 1e9 + 5;
const int MAXN = 5005;

int n, m;
ll T;
vector<pair<int, int>> adj[MAXN];
ll dp[MAXN][MAXN]; // dp[u][len] = min time to reach u in len steps
int parent[MAXN][MAXN];

void solve() {
  cin >> n >> m >> T;

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
  }

  for (int i = 1; i <= n; ++i)
    fill(dp[i], dp[i] + n + 1, LLONG_MAX);

  dp[1][1] = 0;

  for (int len = 1; len <= n; ++len) {
    for (int u = 1; u <= n; ++u) {
      if (dp[u][len] == LLONG_MAX)
        continue;
      for (auto &[v, w] : adj[u]) {
        if (dp[u][len] + w < dp[v][len + 1]) {
          dp[v][len + 1] = dp[u][len] + w;
          parent[v][len + 1] = u;
        }
      }
    }
  }

  int max_len = 0;
  for (int len = n; len >= 1; --len) {
    if (dp[n][len] <= T) {
      max_len = len;
      break;
    }
  }

  cout << max_len << '\n';
  vector<int> path;
  int cur = n, len = max_len;
  while (len > 0) {
    path.push_back(cur);
    cur = parent[cur][len];
    len--;
  }
  reverse(path.begin(), path.end());
  for (int v : path)
    cout << v << " ";
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
