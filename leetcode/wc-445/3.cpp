#include <algorithm>
#include <bits/stdc++.h>
#include <map>

using namespace std;

class Solution {
public:
  typedef long long ll;
  int n;
  vector<ll> factorial;

  void computeFact() {
    for (int i = 1; i <= n; ++i) {
      factorial[i] = factorial[i - 1] * i;
    }
  }
  string getKthPermutation(string s, int k) {
    sort(s.begin(), s.end());
    k--;
    while (k-- && next_permutation(s.begin(), s.end()))
      ;
    return s;
  }

  string smallestPalindrome(string s, int k) {
    n = s.length();
    factorial.resize(n + 1, 1);
    computeFact();
    string forward = "", mid = "";
    map<char, int> mp;

    for (const char &ch : s) {
      mp[ch]++;
    }

    ll possiblePermutations = factorial[n / 2];

    for (auto &it : mp) {
      char ch = it.first;
      if (it.second % 2 != 0 && mid.empty())
        mid.push_back(ch);

      int occur = it.second / 2;
      while (occur--) {
        forward.push_back(ch);
      }

      possiblePermutations /= factorial[it.second / 2];
    }

    if (k == 1) {
      string backward = forward;
      reverse(backward.begin(), backward.end());
      return forward + mid + backward;
    }

    if (k > possiblePermutations) {
      return "";
    }

    string newF = getKthPermutation(forward, k);
    string newB = newF;
    reverse(newB.begin(), newB.end());

    if (!mid.empty())
      return newF + mid + newB;

    return newF + newB;
  }
};
