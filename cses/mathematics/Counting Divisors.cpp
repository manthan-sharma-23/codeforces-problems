#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int x;
  cin >> x;

  int count = 0;

  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      count++;
      if (i != x / i)
        count++;
    }
  }

  cout << count << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}