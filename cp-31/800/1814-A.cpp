#include <iostream>

using namespace std;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n, k;
  cin >> n >> k;

  for (int x = 0; x < 2; ++x) {
    if (n - x * k >= 0 && (n - x * k) % 2 == 0) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
