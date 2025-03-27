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
  vector<int> a(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> dp(n, 1);
  int maxi = 1;

  for (int i = 1; i < n; i++) {
    int l = 0, h = i - 1, res = -1;

    while (l <= h) {
      int mid = l + ((h - l) / 2);

      if (a[mid] < a[i]) {
        res = mid;
        l = mid + 1;
      } else {
        h = mid - 1;
      }
    }

    if (res != -1) {
      dp[i] = max(dp[i], dp[res] + 1);
    }

    maxi = max(maxi, dp[i]);
  }

  cout << maxi << endl;
}

int main() {
  fastIO();
  solve();
  return 0;
}
