#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;

  ll sum = 0;

  for (int k = 1; k <= n; k++) {
    sum += (n / k) * k;
    sum %= MOD;
  }

  cout << sum << endl;
}

int main() {
  fastIO();
  solve();

  return 0;
}