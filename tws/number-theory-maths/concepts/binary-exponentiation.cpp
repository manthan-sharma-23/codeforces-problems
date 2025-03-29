#include <iostream>
using namespace std;

//  sqrt(N)
long long power(long long base, long long power) {
  long long res = 1;
  while (power > 0) {
    if (power & 1) {
      res *= base;
    }
    base *= base;
    power /= 2;
  }
  return res;
}



int main() {
  long long n, m;
  cin >> n >> m;
  cout << power(n, m) << endl;
}
