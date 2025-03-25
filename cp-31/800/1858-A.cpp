#include <iostream>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  if ((c & 1))
    b--;

  if (a > b) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
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