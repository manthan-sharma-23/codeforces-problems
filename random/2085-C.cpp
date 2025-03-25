#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

int extractMSBAndShift(int n) {
  if (n == 0)
    return 0;

  int msb = 1 << (int)log2(n);

  return msb << 1;
}

void solve() {
  int x, y;

  cin >> x >> y;

  if (x == y) {
    cout << -1 << endl;
  } else if (x > y) {
    cout << extractMSBAndShift(x) - x << endl;
  } else {
    cout << extractMSBAndShift(y) - y << endl;
  }
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}