#include <bits/stdc++.h>
#define hash_map(T1, T2) unordered_map<T1, T2, custom_hash>
using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

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

void solve() {
  int n, k;
  cin >> n >> k;
  hash_map(int, ll) freq;

  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    int rem = v % k;
    if (rem != 0) {
      int needed = k - rem;
      freq[needed]++;
    }
  }

  ll maxTime = 0;
  for (auto &[needed, count] : freq) {
    ll time = needed + (count - 1) * 1LL * k;
    maxTime = max(maxTime, time);
  }

  if (maxTime == 0)
    cout << 0 << '\n';
  else
    cout << maxTime + 1 << '\n';
}

int main() {
  fastIO();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
