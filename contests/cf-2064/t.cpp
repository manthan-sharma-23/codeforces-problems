#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      mp[v[i]]++;
    }
    int l = -1, r = -1, current = 0, mx = 0;
    for (int i = 0; i < n; i++) {
      if (mp[v[i]] == 1)
        current++;
      else
        current = 0;
      if (current > mx) {
        mx = current;
        r = i;
        l = i - current + 1;
      }
    }
    if (mx == 0)
      cout << 0 << endl;
    else
      cout << l + 1 << " " << r + 1 << endl;
  }
}