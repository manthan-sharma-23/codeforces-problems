#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
int n, k;
vector<int> a;
string allVisited;

int f(string s, int i, int k) {
  if (k == 1) {
    auto t = s.find('1');
    auto r = s.rfind('1');

    int ans = INT_MIN;
    if (t > 0)
      ans = a[0];

    if (t < n - 1) {
      ans = max(ans, a[n - 1]);
    }

    for (int c = t; c <= r; c++) {
      if (s[c] == '0')
        ans = max(ans, a[c]);
    }

    return ans;
  }

  if (i > n || k > (n - i + 1)) {
    return INT_MIN;
  }

  // pick
  int notPick = f(s, i + 1, k);
  s[i] = '1';
  int pick = a[i] + f(s, i + 1, k - 1);
  s[i] = '0';

  return max(pick, notPick);
}

void solve() {

  cin >> n >> k;
  a.resize(n);
  int maxi = -1, maxE = INT_MIN;
  for (int i = 0; i < n; i++) {
    cin >> a[i];

    if (a[i] > maxE) {
      maxE = a[i];
      maxi = i;
    }
  }

  if (k == 1) {
    int sum = maxE;

    int maxe = INT_MIN;

    for (int i = 0; i < maxi; i++) {
      maxe = max(maxe, a[i]);
    }

    for (int i = maxi + 1; i < n; i++) {
      maxe = max(maxe, a[i]);
    }

    cout << sum + maxe << endl;
    return;
  }

  int sum = 0;

  int nk = k + 1;

  sort(a.begin(), a.end());
  while (nk > 0) {
    sum += a[n - nk];
    nk--;
  }

  cout << sum << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}