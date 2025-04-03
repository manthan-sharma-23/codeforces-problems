#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n, q, k;
  cin >> n >> q >> k;

  vector<int> a(n + 1);
  vector<pair<int, int>> queries(q);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < q; i++) {
    cin >> queries[i].first >> queries[i].second;
  }

  vector<ll> b(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    int high = (i + 1 > n ? k + 1 : a[i + 1]);
    int low = (i - 1 < 1 ? 0 : a[i - 1]);

    b[i] = max(0LL, high - low - 2LL);
    b[i] += b[i - 1];
  }

  vector<ll> res;
  for (const auto &Q : queries) {
    int l = Q.first, r = Q.second;

    if (l == r) {
      res.push_back(k - 1);
      continue;
    }

    ll count = b[r - 1] - b[l];

    count += max(0LL, a[l + 1] - 2LL);
    count += max(0LL, k - a[r - 1] - 1LL);

    res.push_back(count);
  }

  for (auto it : res) {
    cout << it << '\n';
  }
}

int main() {
  fastIO();
  solve();
  return 0;
}
