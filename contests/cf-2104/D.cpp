#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool is_prime(int num) {
  if (num <= 1)
    return false;
  if (num == 2)
    return true;
  if (num % 2 == 0)
    return false;
  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0)
      return false;
  }
  return true;
}

vector<ll> get_first_n_primes(int n) {
  vector<ll> primes;
  int cur = 2;
  while (primes.size() < n) {
    if (is_prime(cur)) {
      primes.push_back(cur);
    }
    cur++;
  }
  return primes;
}

int solve(vector<int> &a, int n) {
  vector<ll> primes = get_first_n_primes(n);
  sort(a.begin(), a.end());

  ll extra = 0;
  int idx = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] >= primes[idx]) {
      extra += a[i] - primes[idx];
      idx++;
    } else {
      if (primes[idx] - a[i] > extra) {
        return (i + 1);
      } else {
        extra -= primes[idx] - a[i];
        idx++;
      }
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << solve(a, n) << '\n';
  }
}
