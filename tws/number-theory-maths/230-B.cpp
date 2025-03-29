#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

set<ll> tPrimes;

void sieve(ll maxN) {
  vector<bool> isPrime(maxN + 1, 1);
  isPrime[0] = isPrime[1] = 0;

  for (ll i = 2; i * i <= maxN; i++) {
    if (isPrime[i]) {
      for (ll j = i * i; j <= maxN; j += i) {
        isPrime[j] = 0;
      }
    }
  }

  for (ll i = 2; i <= maxN; i++) {
    if (isPrime[i]) {
      tPrimes.insert(i * i);
    }
  }
}

void solve() {
  int n;
  cin >> n;

  while (n--) {
    ll t;
    cin >> t;

    if (tPrimes.find(t) != tPrimes.end()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

int main() {
  fastIO();
  sieve(1e6);
  solve();
  return 0;
}
