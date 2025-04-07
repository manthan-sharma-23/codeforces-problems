#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

ll countValidBs(ll n) {
  int maxN = sqrt(n);
  ll low = 1, high = maxN, res = 0;

  while (low <= high) {
    ll mid = low + (high - low) / 2;

    if (mid * mid <= n) {
      res = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return (res - 1) / 2 + 1;
}

int main() {
  ll n;
  cin >> n;

  ll totalCount = 0;

  for (ll powerOf2 = 2; powerOf2 <= n; powerOf2 *= 2) {
    totalCount += countValidBs(n / powerOf2);
  }

  cout << totalCount << endl;
  return 0;
}
