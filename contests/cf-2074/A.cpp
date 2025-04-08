#include <bits/stdc++.h>
#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

double squareRoot(ll number, double precision = 1e-6) {
  double low = 0, high = number, mid;

  while (high - low > precision) {
    mid = low + (high - low) / 2;
    if (mid * mid > number)
      high = mid;
    else
      low = mid;
  }

  return low;
}

double side(double c1, double c2) { return squareRoot(c1 * c1 + c2 * c2); }

void solve() {
  int l, r, d, u;
  cin >> l >> r >> d >> u;

  if (l == r && r == d && d == u)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

int main() {
  fastIO();
  tc solve();
  return 0;
}
