#include <algorithm>
#include <climits>
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
  int n;
  cin >> n;
  vector<int> V(n);

  for (int i = 0; i < n; i++) {
    cin >> V[i];
  }

  sort(V.begin(), V.end());

  if (n == 2) {
    for (int i = 0; i < n; i++) {
      cout << V[i] << " ";
    }
    return;
  }
  int diff = INT_MAX, pos = 0;
  for (int i = 1; i < n; i++) {
    if (V[i] - V[i - 1] < diff) {
      pos = i;
      diff = V[i] - V[i - 1];
    }
  }

  for (int i = pos; i < n; i++) {
    cout << V[i] << " ";
  }

  for (int i = 0; i < pos; i++) {
    cout << V[i] << " ";
  }

  cout << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
