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

const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void usaco() {
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
}

void io(bool _usaco = false) {
  if (_usaco)
    usaco();
  else
    fastIO();
}

int canWin(int a, int b) {
  return (a == 1 && b == 0) || (a == 0 && b == 2) || (a == 2 && b == 1);
}

void solve() {
  int N, K;
  cin >> N >> K;

  vi f(N);

  loop(i, 0, N, +1) {
    char ch;
    cin >> ch;

    if (ch == 'H')
      f[i] = 0;
    else if (ch == 'P')
      f[i] = 1;
    else
      f[i] = 2;
  }

  vector<vector<vi>> dp(N + 1, vector<vi>(K + 1, vi(3, 0)));

  loop(i, 1, N + 1, 1) loop(k, 0, K + 1, 1) loop(t, 0, 3, 1) {
    int win = canWin(t, f[i - 1]);

    loop(z, 0, 3, 1) {
      if (z == t)
        dp[i][k][t] = dp[i - 1][k][t] + win;
      else if (k > 0)
        dp[i][k][t] = max(dp[i][k][t], dp[i - 1][k - 1][z] + win);
    }
  }

  int ans = 0;
  loop(k, 0, K + 1, 1) loop(t, 0, 3, 1) ans = max(ans, dp[N][k][t]);

  cout << ans << "\n";
}

int main() {
  io(false);
  solve();
  return 0;
}
