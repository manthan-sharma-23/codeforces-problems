#include <bits/stdc++.h>
#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2>
#define hash_set(T) unordered_set<T>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> juices(n + 1, vector<int>(2));
  int allVits = 7;

  for (int i = 1; i <= n; i++) {
    int ci;
    cin >> ci;
    string si;
    cin >> si;

    int mask = 0;
    each(c, si) { mask |= (1 << (c - 'A')); }

    juices[i][0] = ci;
    juices[i][1] = mask;
  }

  vector<vector<int>> dp(n + 1, vector<int>(allVits + 1, INT_MAX));
  dp[0][0] = 0;

  for (int i = 1; i <= n; i++) {
    int ci = juices[i][0], viti = juices[i][1];

    for (int m = 0; m <= allVits; m++) {
      dp[i][m] = dp[i - 1][m];

      int left = m & (~viti);
      if (dp[i - 1][left] != INT_MAX) {
        dp[i][m] = min(dp[i][m], dp[i - 1][left] + ci);
      }
    }
  }

  int ans = dp[n][allVits];
  cout << (ans == INT_MAX ? -1 : ans) << endl;
}

int main() {
  fastIO();
  solve();
  return 0;
}
