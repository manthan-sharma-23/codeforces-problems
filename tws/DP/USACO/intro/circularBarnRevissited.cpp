#include <bits/stdc++.h>
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
const ll INF = 1e18;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void usaco(string name = "h") {
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}

ll totalDist(const vi &barns, int start, const int n, int K) {
  vi a(n);
  for (int i = 0; i < n; i++)
    a[i] = barns[(start + i) % n];

  vector<vll> dp(n + 1, vll(K + 1, INF));
  dp[0][0] = 0;

  vll pref(n + 1, 0), w_pref(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
    w_pref[i + 1] = w_pref[i] + 1LL * i * a[i];
  }

  vector<vll> cost(n, vll(n + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cost[i][j] = w_pref[j] - w_pref[i] - 1LL * i * (pref[j] - pref[i]);
    }
  }

  for (int k = 1; k <= K; k++) {
    for (int i = 1; i <= n; i++) {
      for (int m = 0; m < i; m++) {
        dp[i][k] = min(dp[i][k], dp[m][k - 1] + cost[m][i]);
      }
    }
  }

  return dp[n][K];
}

void solve() {
  int n, k;
  cin >> n >> k;
  vi barns(n);

  each(it, barns) cin >> it;

  ll minD = INF;

  for (int i = 0; i < n; i++) {
    minD = min(minD, totalDist(barns, i, n, k));
  }

  cout << minD << endl;
}

int main() {
  usaco("cbarn2");
  fastIO();
  solve();
  return 0;
}