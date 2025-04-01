#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
int n, m, k;

bool check_bench(int bench) {
  ll seats = ((m / (bench + 1)) * bench) + (m % (bench + 1));

  return (ll)(seats * n) >= (ll)k;
}

void solve() {
  n = m = k = 0;
  cin >> n >> m >> k;

  int l = 1, r = m, bench = m;

  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (check_bench(mid)) {
      bench = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << bench << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}