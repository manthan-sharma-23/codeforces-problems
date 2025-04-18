#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void getPrimeFactors(int n, vector<int> &factors) {
  for (int i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      factors.push_back(i);
      n /= i;
    }
  }
  if (n > 1)
    factors.push_back(n);
}

long long maxProductLEK(int n, int k) {
  vector<int> factors;
  getPrimeFactors(n, factors);

  set<long long> products = {1};
  for (int p : factors) {

    vector<long long> newProducts;
    for (long long val : products) {
      long long newVal = val * p;
      if (newVal <= k) {
        newProducts.push_back(newVal);
      }
    }

    for (long long val : newProducts) {
      products.insert(val);
    }
  }

  long long result = 1;
  for (long long val : products) {

    if (val <= k)
      result = max(result, val);
  }

  return result;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    cout << (n / maxProductLEK(n, k)) << endl;
  }
  return 0;
}
