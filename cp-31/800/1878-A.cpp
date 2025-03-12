#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {

  int n, k;
  cin >> n >> k;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    mp[t]++;
  }

  if (mp[k] <= 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
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