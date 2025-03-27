#include <iostream>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;

  if (n % 2 == 0)
    cout << "-1\n";
  else {
    for (int j = 1; j <= n; j++) {
      cout << (2 * (j - 1)) % n + 1 << (j < n ? " " : "\n");
    }
  }
}

int main() {
  fastIO();
  int t;
  cin >> t;
  while (t--)
    solve();
}