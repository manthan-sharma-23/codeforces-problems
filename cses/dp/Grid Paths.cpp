#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

vector<string> grid;
vector<vector<int>> memo;

bool isValid(int r, int c, int n) {
  return r >= 0 && c >= 0 && r < n && c < n && grid[r][c] != '*';
}

int dfs(int r, int c, int n) {
  if (r == n - 1 && c == n - 1) {
    return 1;
  }

  if (memo[r][c] != -1)
    return memo[r][c];

  int ways = 0;

  if (isValid(r, c + 1, n))
    ways = (ways + dfs(r, c + 1, n)) % MOD;

  if (isValid(r + 1, c, n))
    ways = (ways + dfs(r + 1, c, n)) % MOD;

  return memo[r][c] = ways;
}

void solve() {
  int n;
  cin >> n;

  grid.resize(n);
  memo.resize(n + 1, vector<int>(n + 1, -1));

  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  if (grid[0][0] == '*') {
    cout << 0 << endl;
    return;
  }

  cout << dfs(0, 0, n) << endl;
}

int main() {
  fastIO();
  solve();

  return 0;
}