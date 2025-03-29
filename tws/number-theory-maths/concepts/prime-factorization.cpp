#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void factorize(int n) {
  unordered_map<int, int> factors;
  int original = n;
  while (n % 2 == 0) {
    factors[2]++;
    n /= 2;
  }

  for (int i = 3; i * i <= n; i += 2) {

    while (n % i == 0) {
      factors[i]++;
      n /= i;
    }
  }

  if (n > 1)
    factors[n]++;

  for (const pair<int, int> &it : factors) {
    cout << it.first << "^" << it.second << " ";
  }
  cout << endl;
}

//  using sieve O(logN)
void factorizeSieve(long long base) {
  vector<int> powers(base + 1, -1);

  for (int i = 2; i <= base; i++) {
    if (powers[i] == -1) {
      for (int j = i + i; j <= base; j += i) {
        if (powers[j] == -1) {
          powers[j] = i;
        }
      }
    }
  }

  vector<int> factors;
  int num = base;
  while (powers[num] != -1) {
    factors.push_back(powers[num]);
    num /= powers[num];
  }

  factors.push_back(num);
}

int main() {
  int n;
  cin >> n;

  factorizeSieve(n);

  return 0;
}