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

pair<ll, pair<int, int>> maxWeightedLCS(const vi &A, const vi &B) {
  int n = A.size();
  vector<vll> dp(n + 1, vll(n + 1, 0LL));
  vector<vector<pair<int, int>>> parent(
      n + 1, vector<pair<int, int>>(n + 1, {-1, -1}));

  int endI = -1, endJ = -1;
  ll maxWeight = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (A[i - 1] == B[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + A[i - 1];
        parent[i][j] = {i - 1, j - 1};
      } else {
        if (dp[i - 1][j] >= dp[i][j - 1]) {
          dp[i][j] = dp[i - 1][j];
          parent[i][j] = {i - 1, j};
        } else {
          dp[i][j] = dp[i][j - 1];
          parent[i][j] = {i, j - 1};
        }
      }
      if (dp[i][j] > maxWeight) {
        maxWeight = dp[i][j];
        endI = i;
        endJ = j;
      }
    }
  }

  vector<int> indices;
  while (endI > 0 && endJ > 0) {
    auto [pi, pj] = parent[endI][endJ];
    if (pi == endI - 1 && pj == endJ - 1 && A[endI - 1] == B[endJ - 1]) {
      indices.push_back(endI - 1);
    }
    endI = pi;
    endJ = pj;
  }

  if (!indices.empty()) {
    reverse(indices.begin(), indices.end());
    return {maxWeight, {indices.front(), indices.back()}};
  } else {
    return {0, {-1, -1}};
  }
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vi b = a;
  sort(b.begin(), b.end());

  auto [maxSum, sI] = maxWeightedLCS(a, b);
  auto [lastFirstI, lastLastI] = sI;

  ll ss = maxSum;

  int loop = 0;
  while (loop++ < 100) {
    vi c;
    for (int k = 0; k < n; k++) {
      if (a[k] < a[lastFirstI]) {
        c.push_back(a[k]);
      }
    }

    if (c.empty())
      break;

    auto [ms2, e2] = maxWeightedLCS(c, b);

    lastFirstI = e2.first;
    lastLastI = e2.second;
    ss += ms2;
  }

  cout << ss << endl << endl << endl;
}

int main() {
  fastIO();

  tc solve();

  return 0;
}
