#include <iostream>
#include <unordered_map>
#include <vector>

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

  vector<ll> a(n, 0);
  unordered_map<ll, ll> mp;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll pairs = 0;

  for (int i = 0; i < n; i++) {
    ll currDiff = a[i] - i;

    if (mp.find(currDiff) == mp.end()) {
      mp[currDiff] = 1;
    } else {
      pairs += mp[currDiff];
      mp[currDiff]++;
    }
  }

  cout << pairs << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}