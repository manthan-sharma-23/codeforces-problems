#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string answerString(string word, int numFriends) {

    int n = word.length();
    int maxC = 0;

    for (int i = 1; i < n; i++) {
      if (word[i] > word[maxC])
        maxC = i;
    }

    vector<int> indxs;

    for (int i = 0; i < n; i++) {
      if (word[maxC] == word[i])
        indxs.push_back(i);
    }

    if (numFriends == 1) {
      return word;
    }

    string best = "";

    for (auto mxc : indxs) {
      int len = (word.length() - mxc) - (numFriends - mxc - 1);

      auto str = word.substr(mxc, len);

      best = max(best, str);
    }

    return best;
  }
};