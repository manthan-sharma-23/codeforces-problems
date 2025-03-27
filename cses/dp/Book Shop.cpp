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
  int n, x;

  cin >> n >> x;

  //  [price,pages]
  vector<vector<int>> books(n, vector<int>(2));

  for (int i = 0; i < n; i++)
    cin >> books[i][0];

  for (int i = 0; i < n; i++)
    cin >> books[i][1];

  sort(books.begin(), books.end());

  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

  for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= x; j++) {
      if (books[i - 1][0] <= j) {
        dp[i][j] =
            max(dp[i - 1][j], books[i - 1][1] + dp[i - 1][j - books[i - 1][0]]);
      }
    }
  }

  cout << dp[n][x] << endl;
}

int main() {
  fastIO();
  solve();

  return 0;
}