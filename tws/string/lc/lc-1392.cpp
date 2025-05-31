#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string longestPrefix(string s) {
    int n = s.length();

    vector<int> pi(n, 0);

    int len = 0;
    pi[0] = 0;

    int i = 1;
    while (i < n) {

      if (s[len] == s[i]) {
        pi[i++] = ++len;
      } else {
        if (len == 0) {
          pi[i++] = 0;
        } else {
          len = pi[len - 1];
        }
      }
    }

    len = pi[n - 1];

    if (len == 0)
      return "";
    else
      return s.substr(0, len);
  }
};