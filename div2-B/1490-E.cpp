#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

bool win(int k, const vector<int> &b) {
  ll power = b[k];

  for (int i = 0; i < b.size(); i++) {
    if (i == k)
      continue;
    if (power < b[i])
      return false;
    power += b[i];
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> b = a;
  sort(b.begin(), b.end());

  int l = 0, r = n - 1, res = -1;

  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (win(mid, b)) {
      r = mid - 1;
      res = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << n - res  << endl;
  for (int i = 0; i < n; i++) {
    if (a[i] >= b[res]) {
      cout << i+1 << " ";
    }
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
