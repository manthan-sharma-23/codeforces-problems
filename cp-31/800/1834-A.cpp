#include <cmath>
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

  int cNeg = 0;
  int sum = 0;

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t == -1)
      cNeg++;

    sum += t;
  }

  if (sum >= 0) {
    if (cNeg & 1) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  } else {

    int positives = sum + cNeg;
    int moves = ceil((double)(cNeg - positives) / 2);
    cNeg -= moves;

    if (cNeg & 1)
      moves++;
    cout << moves << endl;
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