#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxSubstrings(string word) {
    int n = (int)word.size();
    vector<vector<int>> positions(26);

    for (int i = 0; i < n; ++i) {
      positions[word[i] - 'a'].push_back(i);
    }

    vector<pair<int, int>> candidates;

    for (int c = 0; c < 26; ++c) {
      const vector<int> &indices = positions[c];
      int n = (int)indices.size();

      for (int i = 0; i < n; ++i) {
        int target = indices[i] + 3;
        auto it =
            std::lower_bound(indices.begin() + i + 1, indices.end(), target);
        for (auto jt = it; jt != indices.end(); ++jt) {
          candidates.emplace_back(indices[i], *jt);
        }
      }
    }

    sort(candidates.begin(), candidates.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.second < b.second;
         });

    int count = 0;
    int lastEnd = -1;
    for (auto &interval : candidates) {
      if (interval.first > lastEnd) {
        ++count;
        lastEnd = interval.second;
      }
    }

    return count;
  }
};
