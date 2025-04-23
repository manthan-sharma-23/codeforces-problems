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

using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vll = vector<ll>;
using vi = vector<int>;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

ll computeDP(const vector<vll> &mat, const vll &cost, int n) {
  vector<vll> dp(n + 1, vll(2, 1e18));
  dp[1][0] = 0;
  dp[1][1] = cost[1];

  for (int i = 2; i <= n; i++) {
    bool same = true, plusOne = true, minusOne = true;

    for (int j = 1; j <= n; j++) {
      if (mat[i][j] == mat[i - 1][j]) {
        same = false;
      }
      if (mat[i][j] == mat[i - 1][j] + 1) {
        plusOne = false;
      }
      if (mat[i][j] == mat[i - 1][j] - 1) {
        minusOne = false;
      }
    }

    if (same) {
      dp[i][0] = min(dp[i][0], dp[i - 1][0]);
      dp[i][1] = min(dp[i][1], cost[i] + dp[i - 1][1]);
    }
    if (plusOne)
      dp[i][0] = min(dp[i][0], dp[i - 1][1]);
    if (minusOne)
      dp[i][1] = min(dp[i][1], cost[i] + dp[i - 1][0]);
  }

  return min(dp[n][0], dp[n][1]);
}

vector<vll> transpose(const vector<vll> &mat, int n) {
  vector<vll> T(n + 1, vll(n + 1));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      T[j][i] = mat[i][j];
  return T;
}

void solveCase() {
  int n;
  cin >> n;

  vector<vll> city(n + 1, vll(n + 1));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> city[i][j];

  vll A(n + 1), B(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> A[i];
  for (int i = 1; i <= n; ++i)
    cin >> B[i];

  ll colCost = computeDP(city, B, n);
  ll rowCost = computeDP(transpose(city, n), A, n);

  if (rowCost + colCost >= 1e14) {
    cout << -1 << endl;
    return;
  }

  cout << rowCost + colCost << "\n";
}

int main() {
  fastIO();
  tc solveCase();
  return 0;
}
