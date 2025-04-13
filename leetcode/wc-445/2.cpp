#include <algorithm>
#include <bits/stdc++.h>
#include <map>

using namespace std;

class Solution {
public:
  string smallestPalindrome(string s) {
    int n = s.length();

    string forward = "", mid = "", backward = "";

    map<char, int> mp;

    for (const char &ch : s) {
      mp[ch]++;
    }

    for (auto &it : mp) {
      char ch = it.first;
      if (it.second % 2 != 0) {
        it.second--;
        if (mid.empty())
          mid.push_back(ch);
      }

      int occur = it.second / 2;

      while (occur--) {
        forward.push_back(ch);
        backward.push_back(ch);
      }
    }

    reverse(backward.begin(), backward.end());

    if (!mid.empty())
      return forward + mid + backward;
    return forward + backward;
  }
};