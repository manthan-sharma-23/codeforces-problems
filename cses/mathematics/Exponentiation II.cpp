#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

long long power(long long base, long long power) {
  long long res = 1;
  while (power > 0) {
    if (power & 1) {
      res = (res * base) % MOD;
    }
    base = (base * base) % MOD;
    power /= 2;
  }
  return res;
}

void solve() {
  ll a, b, c;

  cin >> a >> b >> c;

  ll g = power(b, c);

  cout << power(a, g) << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}