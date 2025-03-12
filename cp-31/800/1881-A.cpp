#include <iostream>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n, m;
  cin >> n >> m;
  string x, s;
  cin >> x >> s;

  if (x.find(s) != string::npos) {
    cout << 0 << endl;
    return;
  }

  int t = 0;
  while (5 >= t++) {
    x += x;
    if (x.find(s) != string::npos) {
      cout << t << endl;
      return;
    }
  }

  cout << -1 << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}