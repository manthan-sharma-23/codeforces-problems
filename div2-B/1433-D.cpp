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
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  vector<vector<bool>> mat(n + 1, vector<bool>(n + 1, true));

  for (int i = 1; i <= n; i++) {
    mat[i][i] = false;
    if (arr[i] > n)
      continue;
    mat[i][arr[i]] = mat[arr[i]][i] = false;
  }

  vector<bool> indegree(n + 1, false);
  vector<pair<int, int>> roads;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((i != j && mat[i][j] && mat[j][i]) && !indegree[j]) {
        roads.push_back({i, j});
        mat[i][j] = mat[j][i] = false;
        indegree[j] = true;
      }
    }
  }

  if (roads.size() == n - 1) {
    cout << "YES" << endl;
    for (auto road : roads) {
      cout << road.first << " " << road.second << endl;
    }
  } else {
    cout << "NO" << endl;
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