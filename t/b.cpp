#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long

int lcp(const string &a, const string &b) {
  int n = min(a.size(), b.size()), i = 0;
  while (i < n && a[i] == b[i])
    ++i;
  return i;
}

class Solution {
public:
  vector<int> longestCommonPrefix(vector<string> &words) {
    int n = words.size();
    if (n <= 1)
      return vector<int>(n);

    vi maxS(n - 1, 0);

    for (int i = 0; i < n - 1; i++) {
      maxS[i] = lcp(words[i], words[i + 1]);
    }

    for (auto s : maxS)
      cout << s << " ";
    cout << endl;

    vi pref(n, 0), suff(n, 0);

    // pref[i] = max of maxS[0..i-1]
    for (int i = 1; i < n; i++) {
      pref[i] = max(pref[i - 1], maxS[i - 1]);
    }

    // suff[i] = max of maxS[i..n-2]
    for (int i = n - 2; i >= 0; i--) {
      suff[i] = max((i + 1 < n ? suff[i + 1] : 0), maxS[i]);
    }

    for (auto s : pref)
      cout << s << " ";
    cout << endl;
    for (auto s : suff)
      cout << s << " ";
    cout << endl << endl;

    vi res(n, 0);
    for (int i = 0; i < n; i++) {
      int maxL = 0;
      cout << i << " ";
      if (i - 1 >= 1) {
        maxL = max(maxL, pref[i - 1]);
      }

      if (i + 1 <= n - 2) {
        cout << "suff[" << i + 1 << "]=" << suff[i + 1] << " ";
        maxL = max(maxL, suff[i + 1]);
      }
      if (i > 0 && i < n - 1) {
        int l = lcp(words[i - 1], words[i + 1]);
        cout << "lcp(" << i - 1 << "," << i + 1 << ")=" << l << " ";
        maxL = max(maxL, l);
      }
      cout << endl;
      res[i] = maxL;
    }

    return res;
  }
};
