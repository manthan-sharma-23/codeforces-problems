#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n - 1);

  for (int i = 0; i < n - 1; i++)
    cin >> a[i];

  cout << -1 * accumulate(a.begin(), a.end(), 0) << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}