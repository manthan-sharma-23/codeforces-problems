#include <bits/stdc++.h>
using namespace std;

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2, custom_hash>

using ll = long long;
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

void solve() {
  int n, k;
  cin >> n >> k;

  vi a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vi dp(n);

  dp[n - 1] = a[n - 1];

  for (int i = n - 2; i >= 0; i--) {
    if (i + k < n) {
      dp[i] = a[i] + dp[i + k];
    } else {
      dp[i] = a[i];
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
  fastIO();
  tc solve();
  return 0;
}
