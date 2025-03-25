#include <climits>
#include <iostream>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;
  bool sorted = true;
  int prev, minD = INT_MAX;
  cin >> prev;
  for (int i = 1; i < n; i++) {
    int t;
    cin >> t;

    if (t < prev) {
      sorted = 0;
    }
    minD = min(minD, t - prev);
    prev = t;
  }
  if (!sorted) {
    cout << 0 << endl;
    return;
  }

  minD++;

  cout << (minD / 2) + minD % 2 << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}