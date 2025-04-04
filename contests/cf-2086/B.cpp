#include <iostream>
#include <vector>

using namespace std;
// manthan's code
typedef long long ll;
const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n, k;
  ll x;
  cin >> n >> k >> x;
  vector<int> a(n + 1, 0);
  vector<ll> pref(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  ll totalSum = k * pref[n];
  if (totalSum < x) {
    cout << 0 << endl;
    return;
  }

  ll count = 0;

  ll low = 1LL, high = 1LL * n * k;

  while (low <= high) {
    ll mid = low + (high - low) / 2;
    ll sum = 0;
    if (mid % n != 0)
      sum = totalSum - ((mid / n) * pref[n]) - pref[max(0LL, (mid % n) - 1LL)];
    else
      sum = totalSum - ((mid / n - 1) * pref[n]) - pref[n - 1];

    if (sum >= x) {
      low = mid + 1;
      count = mid;
    } else {
      high = mid - 1;
    }
  }

  cout << count << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
