#include <iostream>
#include <unordered_set>
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

  vector<int> hash(n, 0);

  hash[0] = (a[0] == 0);

  for (int i = 1; i < n; i++) {
    hash[i] = hash[i - 1] + (a[i] == 0);
  }

  int mid = n / 2;

  bool left = false, right = false;

  if (hash[mid - 1] > 0) {
    left = true;
  }
  if (hash[n - 1] - hash[mid - 1] > 0)
    right = true;

  if (right && left) {
    cout << 3 << endl;
    cout << 1 << " " << mid << endl;
    cout << 2 << " " << (n - mid + 1) << endl;
    cout << 1 << " " << 2 << endl;
  } else if (right) {
    cout << 2 << endl;
    cout << mid + 1 << " " << n << endl;
    cout << 1 << " " << mid + 1 << endl;
  } else if (left) {
    cout << 2 << endl;
    cout << 1 << " " << mid << endl;
    cout << 1 << " " << (n - mid + 1) << endl;
  } else {
    cout << 1 << endl;
    cout << 1 << " " << n << endl;
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