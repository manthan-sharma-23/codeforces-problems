#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumTimeToInitialState(string word, int k) {
    int n = word.length();

    vector<int> lps(n, 0);

    int len = 0, i = 1;
    while (i < n) {
      if (word[len] == word[i])
        lps[i++] = ++len;
      else {
        if (len == 0) {
          lps[i++] = 0;
        } else {
          len = lps[len - 1];
        }
      }
    }

    int x = lps[n - 1];

    while (x > 0 && (n - x) % k != 0) {
      x = lps[x - 1];
    }

    if ((n - x) % k == 0)
      return ((n - x - 1) / k) + 1;
    else
      return ceil((double)n / k);
  }
};