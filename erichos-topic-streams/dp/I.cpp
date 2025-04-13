#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

int computeRowScore(const int r, const vector<vector<int>> &matrix) {

  int score = 0, cnt = 0;

  for (int i = 0; i < matrix[r].size(); i++) {
    if (matrix[r][i] == 0)
      cnt = 0;
    else
      cnt++;

    score = max(score, cnt);
  }
  score = max(score, cnt);

  return score;
}

void solve() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int>> matrix(n, vector<int>(m, 0));
  multiset<int> rowScores;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
    rowScores.insert(computeRowScore(i, matrix));
  }

  while (q--) {
    int r, c;
    cin >> r >> c;
    r--, c--;

    int oldScore = computeRowScore(r, matrix);
    rowScores.erase(rowScores.find(oldScore));

    if (matrix[r][c] == 1)
      matrix[r][c] = 0;
    else {
      matrix[r][c] = 1;
    }
    rowScores.insert(computeRowScore(r, matrix));
    cout << *rowScores.rbegin() << endl;
  }
}
int main() {
  fastIO();
  solve();
  return 0;
}
