#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<bool> vis(n + 1, false);
  ll count = 0;
  for (ll i = 0; i < k; i++) {
    int p;
    cin >> p;

    for (ll j = p; j <= n; j += p) {
      if (!vis[j]) {
        count++;
        vis[j] = true;
      }
    }
  }

  cout << count << endl;
}

int main() {
  fastIO();
  solve();

  return 0;
}