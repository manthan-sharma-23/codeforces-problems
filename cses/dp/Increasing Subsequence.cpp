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

  vector<int> dp;

  for (int i = 0; i < n; i++) {
    int val = a[i];
    auto it = lower_bound(dp.begin(), dp.end(), val);
    if (it == dp.end())
      dp.push_back(val);
    else
      *it = val;
  }

  cout << dp.size() << endl;
}

int main() {
  fastIO();
  solve();
  return 0;
}
