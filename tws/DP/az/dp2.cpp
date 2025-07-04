#include <bits/stdc++.h>
#include <cstring>
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

int n, q;
vi a, b;

bool dp[101][100001];

void solve() {
  cin >> n >> q;

  memset(dp, false, sizeof(dp));
  a.assign(n, 0);
  b.assign(q, 0);

  each(it, a) cin >> it;
  each(it, b) cin >> it;

  dp[0][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 100000; j++) {
      if (a[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j] || (j >= a[i - 1] && dp[i - 1][j - a[i - 1]]);
      }
    }
  }

  vector<vector<int>> res(q);

  int i = 0;
  while (i < q) {
    int sum = b[i];

    int k = n;
    while (sum >= 0) {
      int prevc = k;
      for (int j = 0; j < k; j++) {
        if (dp[j + 1][sum]) {
          k = j;
          break;
        }
      }

      if (k == prevc) {
        res[i] = {-1};
        break;
      } else {
        sum -= a[k];
        res[i].push_back(k);
      }
    }

    i++;
  }

  for (int i = 0; i < q; i++) {
    each(num, res[i]) { cout << num << " "; }
    cout << endl;
  }
}

int main() {
  // usaco();
  fastIO();
  solve();

  return 0;
}
