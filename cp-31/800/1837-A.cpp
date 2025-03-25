#include <iostream>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int x, k;
  cin >> x >> k;

  if (x % k == 0) {
    cout << 2 << endl;
    cout << x - 1 << " " << 1 << endl;
  } else {
    cout << 1 << endl;
    cout << x << endl;
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