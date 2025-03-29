#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int maxActiveSectionsAfterTrade(string s) {
    vector<pair<int, int>> V;

    int el = s[0] - '0', count = 1;
    for (int i = 1; i < s.length(); i++) {
      if ((s[i] - '0') == el) {
        count++;
      } else {
        V.push_back({el, count});
        el = s[i] - '0';
        count = 1;
      }
    }
    if (count > 0)
      V.push_back({el, count});

    int count1s = 0;
    for (auto it : V) {
      if (it.first == 1)
        count1s += it.second;
    }

    int n = V.size();
    int maxScore = 0;

    for (int i = 0; i < n; i++) {
      if (V[i].first == 1) {
        int score = count1s;
        if (i - 1 >= 0 && i + 1 < n) {
          score += (V[i - 1].second + V[i + 1].second);
        }
        maxScore = max(maxScore, score);
      }
    }

    return maxScore;
  }
};