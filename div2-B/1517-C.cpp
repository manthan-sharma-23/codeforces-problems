#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void printTriangle(vector<vector<int>> &mat) {
  int n = mat.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> mat(n, vector<int>(n, -1));

  for (int i = 0; i < n; i++)
    cin >> mat[i][i];

  for (int i = 0; i < n; i++) {
    int region = mat[i][i];
    int r = i, c = i;
    int count = region - 1;

    while (count > 0) {
      if (c - 1 >= 0 && mat[r][c - 1] == -1) {
        mat[r][--c] = region;
      } else if (r + 1 < n && mat[r + 1][c] == -1) {
        mat[++r][c] = region;
      } else {
        cout << -1 << endl;
        return;
      }
      count--;
    }
  }

  printTriangle(mat);
}

int main() {
  fastIO();
  solve();
  return 0;
}
