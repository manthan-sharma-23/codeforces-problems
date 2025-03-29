#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
const int maxN = 1e6;

void solve() {
  int n;
  cin >> n;

  unordered_map<int, int> freq;

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    freq[t]++;
  }

  for (int g = maxN; g >= 1; g--) {
    ll count = 0;
    for (int i = g; i <= maxN; i += g) {
      count += freq[i];
      if (count >= 2) {
        cout << g << endl;
        return;
      }
    }
  }

  cout << 1 << endl;
}

int main() {
  fastIO();
  solve();

  return 0;
}