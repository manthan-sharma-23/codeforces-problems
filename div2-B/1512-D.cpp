#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef long long L;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;

  vector<int> arr(n + 2);

  for (int i = 0; i < n + 2; i++)
    cin >> arr[i];

  sort(arr.begin(), arr.end());

  L tSum = arr[arr.size() - 1];
  L totalSum = accumulate(arr.begin(), arr.end(), 0) - tSum;

  for (int i = 0; i < n + 1; i++) {
    L lSum = totalSum - arr[i];

    if (lSum == tSum) {
      for (int j = 0; j < n + 1; j++) {
        if (j == i)
          continue;

        cout << arr[j] << " ";
      }
      cout << endl;
      return;
    }
  }

  tSum = arr[arr.size() - 2];
  totalSum = 0;

  for (int i = 0; i < n; i++) {
    totalSum += arr[i];
  }

  if (totalSum == tSum) {
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;

    return;
  }

  cout << -1 << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}