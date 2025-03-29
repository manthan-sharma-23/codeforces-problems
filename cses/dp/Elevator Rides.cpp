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

int allVisited;

int f(int mask, int wt, const vector<int> &arr) {
  if (mask == allVisited)
    return 0;

  int minTurns = INT_MAX;
  for (int i = 0; i < arr.size(); i++) {
    if (mask & (1 << i))
      continue;

    f(mask | (1 << i), wt - arr[i], arr);
  }
}

void solve() {
  int n, x;
  cin >> n >> x;
  allVisited = (1 << n) - 1;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
}

int main() {
  fastIO();
  solve();

  return 0;
}