#include <bits/stdc++.h>
// manthan's code

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
  ll n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  vector<bool> valid(26, false);

  for (int i = 0; i < k; i++) {
    char c;
    cin >> c;
    valid[c - 'a'] = true;
  }

  vector<ll> dp(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    if (valid[s[i - 1] - 'a']) {
      dp[i] = dp[i - 1] + 1;
    }
  }

  cout << (ll)accumulate(dp.begin(), dp.end(), 0LL) << endl;
}

int main() {
  fastIO();
  solve();
  return 0;
}
