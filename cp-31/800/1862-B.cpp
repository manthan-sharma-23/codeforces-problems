#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

void solve() {
  int n;
  cin >> n;

  if (n == 0) {
    cout << endl;
    return;
  }

  vector<int> b(n);
  for (int i = 0; i < n; i++)
    cin >> b[i];

  vector<int> a;
  a.push_back(b[0]);

  for (int i = 1; i < n; i++) {
    if (b[i] < *a.rbegin())
      a.push_back(1);
    a.push_back(b[i]);
  }
  cout << a.size() << endl;
  for (auto n : a) {
    cout << n << " ";
  }
  cout << endl;
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}