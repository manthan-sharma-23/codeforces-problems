#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

int josephus_kth_removed(int n, int k) {
  vector<bool> removed(n + 1, false);
  int remaining = n, count = 0, index = 0;

  while (remaining > 0) {
    int skipped = 0;

    while (skipped < 1) {
      index = (index + 1) % n;
      if (!removed[index])
        skipped++;
    }

    removed[index] = true;
    count++;

    if (count == k)
      return index + 1;
    remaining--;
  }

  return -1;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<bool> a(n, false);

  cout << josephus_kth_removed(n, k) << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}