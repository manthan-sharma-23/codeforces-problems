#include <bits/stdc++.h>
using namespace std;

// longest prefix suffix till index 'i' in string 't'
vector<int> Lps(string t) {
  int m = t.length();
  vector<int> lps(m, 0);

  int i = 1, len = 0;
  while (i < m) {
    if (t[i] == t[len]) {
      lps[i] = ++len;
      i++;
    } else {
      if (len > 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }

  return lps;
}

int main() {

  int m;
  cin >> m;

  string s;
  cin >> s;

  auto vlps = Lps(s);

  for (int i = 0; i < m; i++) {
    cout << i << " " << vlps[i] <<endl;
  }

  return 0;
}