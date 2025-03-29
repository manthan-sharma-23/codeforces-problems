#include <iostream>
#include <numeric>
#include <set>
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

  int tSum = accumulate(a.begin(), a.end(), 0);

  vector<vector<bool>> dp(n + 1, vector<bool>(tSum + 1, false));

  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }

  set<int> s;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= tSum; j++) {
      if (a[i - 1] <= j)
        dp[i][j] = dp[i][j] || dp[i - 1][j - a[i - 1]];

      dp[i][j] = dp[i][j] || dp[i - 1][j];
    }
  }

  int count = 0;
  vector<int> fs;

  for (int i = 1; i <= tSum; i++) {
    if (dp[n][i]) {
      count++;
      fs.push_back(i);
    }
  }

  cout << count << endl;
  for (auto num : fs) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  fastIO();
  solve();

  return 0;
}