#include <bits/stdc++.h>

#define tc                                                                     \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2>
#define hash_set(T) unordered_set<T>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

const int MAX_FACTORIAL = 500001;
vector<ll> fact(MAX_FACTORIAL + 1);

void compute_factorials() {
  fact[0] = 1;
  for (int i = 1; i <= MAX_FACTORIAL; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
}

const int MAX_SIEVE = 1e6;
vector<bool> isPrime(MAX_SIEVE + 1, 1);

void sieve() {
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i * i <= MAX_SIEVE; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX_SIEVE; j += i) {
        isPrime[j] = 0;
      }
    }
  }
}

ll mod_expo(ll base, ll exp, ll mod) {
  ll result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

ll mod_inv(ll a, ll mod) { return mod_expo(a, mod - 2, mod); }

bool elementExists(const vector<int> &sortedUniqueNums, int target) {
  int left = 0, right = sortedUniqueNums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (sortedUniqueNums[mid] == target) {
      return true;
    } else if (sortedUniqueNums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return false;
}

void solve() {
  int arraySize;
  cin >> arraySize;

  vector<int> numbers(arraySize);
  for (int i = 0; i < arraySize; i++) {
    cin >> numbers[i];
  }

  int minValue = *min_element(numbers.begin(), numbers.end());
  int maxValue = *max_element(numbers.begin(), numbers.end());

  set<int> uniqueSet(numbers.begin(), numbers.end());
  vector<int> sortedUniqueNums(uniqueSet.begin(), uniqueSet.end());

  int twiceMin = minValue * 2;
  int twiceMax = maxValue * 2;
  int sumMinMax = minValue + maxValue;

  if (!elementExists(sortedUniqueNums, twiceMin)) {
    cout << minValue << " " << minValue << endl;
  } else if (!elementExists(sortedUniqueNums, twiceMax)) {
    cout << maxValue << " " << maxValue << endl;
  } else if (!elementExists(sortedUniqueNums, sumMinMax)) {
    cout << minValue << " " << maxValue << endl;
  } else {
    cout << -1 << endl;
  }
}

int main() {
  fastIO();
  tc solve();
  return 0;
}
