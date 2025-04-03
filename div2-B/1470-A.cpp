#include <algorithm>
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

void solve() {
  int n, m;

  cin >> n >> m;

  vector<int> people(n);
  vector<ll> cost(m);

  for (int i = 0; i < n; i++)
    cin >> people[i];

  for (int i = 0; i < m; i++)
    cin >> cost[i];

  vector<bool> taken(m, false);

  sort(people.begin(), people.end());

  ll totalCost = 0;

  for (int i = n - 1; i >= 0; i--) {
    int P = people[i] - 1;

    ll dollars = (P) < m ? cost[P] : INT_MAX;

    int gift = -1, l = 0, r = min(m - 1, P);

    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (!taken[mid]) {
        r = mid - 1;
        gift = mid;
      } else {
        l = mid + 1;
      }
    }

    if (gift == -1 || dollars <= cost[gift]) {
      totalCost += dollars;
    } else {
      taken[gift] = true;
      totalCost += cost[gift];
    }
  }

  cout << totalCost << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}