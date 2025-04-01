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

int LARGE = 1e7 + 1;
vector<bool> isPrime(LARGE + 1);

vector<bool> sieve(int maxN = LARGE) {
  vector<bool> isPrime(maxN + 1, 1);

  isPrime[0] = isPrime[1] = 0;

  for (int i = 2; i * i <= maxN; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= maxN; j += i) {
        isPrime[j] = 0;
      }
    }
  }

  return isPrime;
}

void solve() {

  int n;
  cin >> n;

  set<pair<int, int>> st;

  vector<int> primes;
  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i; j <= n; j += i) {
        count++;
      }
    }
  }

  cout << count << endl;
}

int main() {
  fastIO();
  isPrime = sieve(LARGE);
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}