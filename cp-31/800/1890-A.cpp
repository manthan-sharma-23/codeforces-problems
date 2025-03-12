#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    a[i] = t;
    mp[t]++;
  }

  if (n == 2) {
    cout << "Yes" << endl;
    return;
  }

  if (mp.size() >= 3) {
    cout << "No" << endl;
    return;
  }

  if (mp.size() == 1) {
    cout << "Yes" << endl;
    return;
  }

  if (abs(mp.begin()->second - mp.rbegin()->second) <= 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
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