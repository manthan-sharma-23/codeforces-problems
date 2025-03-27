#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n, m, c;
  cin >> n >> m >> c;

  int k = c;

  int alterNateArrange = ceil((double)m / 2) * n;

  if (alterNateArrange >= k) {
    cout << 1 << endl;
    return;
  }

  int colsNeeded = ceil((double)k / n);
  if (colsNeeded == m)
    cout << m << endl;
  else
    cout << ceil(double(colsNeeded) / 2) << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}