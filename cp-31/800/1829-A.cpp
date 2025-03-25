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
  int countMax = 0;
  int count = 0;

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;

    if (t == 1) {
      countMax = max(countMax, count);
      count = 0;
    } else {
      count++;
    }
  }
  countMax = max(countMax, count);
  cout << countMax << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}