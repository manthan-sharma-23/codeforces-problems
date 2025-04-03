#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

vector<ll> factors = {11, 111};

void solve() {
  int n;
  cin >> n;

  if (n < 11) {
    cout << "NO" << endl;
    return;
  }

  int max11 = n / 11;

  for (int i = max11; i >= 0; i--) {
    int rem = n - (i * 11);
    if (rem % 111 == 0) {
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
