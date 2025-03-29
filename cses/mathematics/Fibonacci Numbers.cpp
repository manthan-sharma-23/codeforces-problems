#include <iostream>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

struct Matrix {
  ll a, b, c, d;

  Matrix operator*(const Matrix &other) {
    return {
        (a * other.a + b * other.c) % MOD, (a * other.b + b * other.d) % MOD,
        (c * other.a + d * other.c) % MOD, (c * other.b + d * other.d) % MOD};
  }
};

Matrix matrix_exponentiation(Matrix A, ll k) {
  Matrix result = {1, 0, 0, 1};
  while (k > 0) {
    if (k % 2 == 1)
      result = result * A;
    A = A * A;
    k /= 2;
  }
  return result;
}

ll fib(ll n) {
  if (n == 0)
    return 0;
  Matrix A = {1, 1, 1, 0};
  return matrix_exponentiation(A, n - 1).a;
}

int main() {
  ll n;
  cin >> n;
  cout << fib(n) << endl;
  return 0;
}
