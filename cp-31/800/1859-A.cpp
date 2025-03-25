#include <algorithm>
#include <iostream>
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

  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end());

  if (a[n - 1] == a[0]) {
    cout << -1 << endl;
  } else {
    vector<int> c;
    int p = a[n - 1];
    a.pop_back();
    c.push_back(p);

    while (*a.rbegin() == p) {
      c.push_back(p);
      a.pop_back();
    }

    cout << a.size() << " " << c.size() << endl;

    for (auto r : a) {
      cout << r << " ";
    }
    cout << endl;

    for (auto r : c) {
      cout << r << " ";
    }
    cout << endl;
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