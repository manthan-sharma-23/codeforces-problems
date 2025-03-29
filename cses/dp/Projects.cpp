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

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> projects(n, vector<int>(3));

  for (int i = 0; i < n; i++) {
    cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
  }

  sort(projects.begin(), projects.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

  vector<ll> dp(n, 0);
  dp[0] = projects[0][2];
  for (int i = 1; i < n; i++) {
    int current_start = projects[i][0];
    int current_profit = projects[i][2];

    int left = 0, right = i - 1, best = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (projects[mid][1] < current_start) {
        best = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    ll profit_with_current =
        (best == -1) ? current_profit : dp[best] + current_profit;
    dp[i] = max(dp[i - 1], profit_with_current);
  }

  cout << dp[n - 1] << endl;
}

int main() {
  fastIO();
  solve();
  return 0;
}