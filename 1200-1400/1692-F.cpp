#include <bits/stdc++.h>
using namespace std;

#define fastIO()                                                               \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0)
#define each(x, v) for (auto &x : v)
typedef long long ll;

vector<vector<int>> validCombinations;

void precomputeCombinations() {
  // Generate all unique a <= b <= c where a + b + c ∈ {3, 13, 23}
  vector<int> targets = {3, 13, 23};
  for (int target : targets) {
    for (int a = 0; a <= 9; ++a) {
      for (int b = a; b <= 9; ++b) {
        for (int c = b; c <= 9; ++c) {
          if (a + b + c == target) {
            validCombinations.push_back({a, b, c});
          }
        }
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  unordered_map<int, int> digitCount;
  for (int &num : a) {
    cin >> num;
    digitCount[num % 10]++;
  }

  for (const vector<int> &comb : validCombinations) {
    unordered_map<int, int> needed;
    for (int d : comb) {
      needed[d]++;
    }

    bool possible = true;
    for (const auto &[digit, cnt] : needed) {
      if (digitCount[digit] < cnt) {
        possible = false;
        break;
      }
    }

    if (possible) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
}

int main() {
  fastIO();
  precomputeCombinations();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}