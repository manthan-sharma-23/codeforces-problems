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

  int maxT = 0;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    maxT = max(maxT, a[i]);
  }
  for (int i = 0; i < n; i++) {
    cout << maxT - a[i] + 1 << " ";
  }

  cout << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}