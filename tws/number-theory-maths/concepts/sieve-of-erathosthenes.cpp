#include <vector>

using namespace std;

// N loglogN
vector<bool> sieve(int maxN = 1e6) {
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