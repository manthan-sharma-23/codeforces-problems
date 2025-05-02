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

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> tr(n);
  for (int i = 0; i < n; i++) {
    cin >> tr[i];
  }

  int left = 0, right = 0, zeroes = 0, maxLen = 0, bestL = 0, bestR = 0;

  while (right < n) {
    if (tr[right] == 0)
      zeroes++;

    while (zeroes > k) {
      if (tr[left] == 0)
        zeroes--;
      left++;
    }

    if (right - left + 1 > maxLen) {
      maxLen = right - left + 1;
      bestL = left;
      bestR = right;
    }

    right++;
  }

  cout << maxLen << endl;
  for (int i = bestL; i <= bestR; i++) {
    tr[i] = 1;
  }

  for (int num : tr) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  fastIO();
  solve();
  return 0;
}
