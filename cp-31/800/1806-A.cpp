#include <iostream>

using namespace std;

typedef long long ll;

bool isOnOrAboveLine(double x1, double y1, double x, double y) {
  double m = 1.0;
  double c = y1 - m * x1;

  return y >= (m * x + c);
}
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int a, b, c, d;

  cin >> a >> b >> c >> d;

  if (!isOnOrAboveLine(a, b, c, d) || (d < b)) {
    cout << -1 << endl;
    return;
  }

  int steps = (d - b) * 2 + (a - c);

  cout << steps << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}