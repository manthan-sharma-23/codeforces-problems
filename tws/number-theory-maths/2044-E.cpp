#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  ll k, l1, r1, l2, r2;

  cin >> k >> l1 >> r1 >> l2 >> r2;

  ll count = 0;
  ll kn = 1;

  while (r2 / kn >= l1) {
    count += max(0ll, min(r2 / kn, r1) - max((l2 - 1) / kn + 1, l1) + 1ll);
    kn *= k;
  }

  cout << count << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}