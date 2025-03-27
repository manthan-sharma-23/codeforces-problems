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
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < m; j++) {
      a[i][j] = row[j] - '0';
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i][j] == 0)
        continue;

      bool f = 1;

      for (int k = 0; k < i; k++) {
        if (a[k][j] == 0) {
          f = false;
          break;
        }
      }

      if (f)
        continue;

      f = 1;

      for (int k = 0; k < j; k++) {
        if (a[i][k] == 0) {
          f = false;
          break;
        }
      }

      if (f)
        continue;

      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
