#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {

  int x, n, m;

  cin >> x >> n >> m;

  // for max
  int cl = m, fl = n;
  int num = x;

  while (cl > 0 && num > 0) {
    if (num % 2 == 0 && fl > 0) {
      num /= 2;
      fl--;
    } else {
      num = ceil((double)num / 2);
      cl--;
    }
  }

  while (fl > 0 && num > 0) {
    num = floor((double)num / 2);
    fl--;
  }

  int maxi = num;

  // min
  cl = m, fl = n, num = x;

  while (fl > 0 && num > 0) {
    if (num % 2 == 0 && cl > 0) {
      num /= 2;
      cl--;
    } else {
      num = floor((double)num / 2);
      fl--;
    }
  }

  while (cl > 0 && num > 0) {
    num = ceil((double)num / 2);
    cl--;
  }

  int mini = num;

  cout << mini << " " << maxi << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}