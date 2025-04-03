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

  int pair = 0;
  for (int i = 1; i <= n; i++) {
    int k = arr[i];

    int start = ((i + k - 1) / k) * k;

    while (start < (2 * i)) {
      int j = start - i;
      if (j > 0 && k * arr[j] == start) {
        pair++;
      }
      start += k;
    }
  }

  cout << pair << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}