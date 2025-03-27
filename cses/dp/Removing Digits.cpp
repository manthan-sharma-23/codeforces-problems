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

vector<int> memo(1e6 + 1, -1);

int f(int num) {
  if (num == 0)
    return 0;
  else if (num / 10 == 0)
    return 1;

  if (memo[num] != -1)
    return memo[num];

  string number = to_string(num);

  int minWays = INT_MAX;

  for (char s : number) {
    int d = s - '0';
    if (d != 0)
      minWays = min(minWays, 1 + f(num - d));
  }

  return memo[num] = minWays;
}

void solve() {
  int n;
  cin >> n;

  cout << f(n) << endl;
}

int main() {
  fastIO();
  solve();

  return 0;
}