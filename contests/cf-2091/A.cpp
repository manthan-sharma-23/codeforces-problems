#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  unordered_map<int, int> mp;
  mp[0] = 3, mp[1] = 1, mp[3] = 1, mp[2] = 2, mp[5] = 1;

  for (int i = 0; i < n; i++) {
    if (mp.find(a[i]) != mp.end()) {
      mp[a[i]]--;
      if (mp[a[i]] == 0) {
        mp.erase(a[i]);
      }
    }

    if (mp.empty()) {
      cout << i + 1 << endl;
      return;
    }
  }

  cout << 0 << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}