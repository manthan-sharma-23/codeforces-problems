#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

const int M = 200001;
ll a[10];
ll b[10];
ll ans[(M + 10)];

void init() {
  memset(a, 0, sizeof(a));

  a[0] = 1LL;
  ll s = 0LL;
  for (int i = 0; i <= M + 10; i++) {
    s = 0LL;
    b[0] = a[9] % MOD;
    b[1] = a[0] % MOD + a[9] % MOD;
    b[2] = a[1] % MOD;
    b[3] = a[2] % MOD;
    b[4] = a[3] % MOD;
    b[5] = a[4] % MOD;
    b[6] = a[5] % MOD;
    b[7] = a[6] % MOD;
    b[8] = a[7] % MOD;
    b[9] = a[8] % MOD;

    for (int l = 0; l < 10; l++) {
      a[l] = b[l];
      s += a[l];
    }
  }
}

void solve() {}

int main() {
  init();
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}