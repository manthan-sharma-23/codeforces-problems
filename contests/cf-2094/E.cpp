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

int findIndexWithMostCommonSetBits(const vector<int> &nums) {
  int n = nums.size();
  int bL = 30;
  vector<int> count(bL, 0);

  for (int num : nums) {
    for (int i = 0; i < bL; i++) {
      if (num & (1 << i)) {
        count[i]++;
      }
    }
  }

  int maxCommonSetBits = -1;
  int bestIndex = -1;

  for (int i = 0; i < n; i++) {
    int commonSetBits = 0;
    for (int j = 0; j < bL; j++) {
      if (nums[i] & (1 << j)) {
        commonSetBits += count[j];
      }
    }

    if (commonSetBits > maxCommonSetBits) {
      maxCommonSetBits = commonSetBits;
      bestIndex = i;
    }
  }

  return bestIndex;
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> setBits(30, 0);
  for (int i = 0; i < n; i++) {
    for (int b = 0; b < 30; b++) {
      if (a[i] & (1 << b)) {
        setBits[b]++;
      }
    }
  }

  ll maxSum = 0;
  for (int i = 0; i < n; i++) {
    ll sum = 0;
    for (int b = 0; b < 30; b++) {
      if (a[i] & (1 << b)) {
        sum += ((ll)(n - setBits[b])) << b;
      } else {
        sum += ((ll)setBits[b]) << b;
      }
    }
    if (sum > maxSum) {
      maxSum = sum;
    }
  }

  cout << maxSum << endl;
}

int main() {
  fastIO();

  tc solve();

  return 0;
}
