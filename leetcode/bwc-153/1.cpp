#include <string>

using namespace std;

class Solution {
public:
  int reverseDegree(string s) {
    int n = s.length();

    long long degree = 0;

    for (int i = 0; i < n; i++) {
      int score =( 26 - (s[i] - 'a')) * (i + 1);
      degree += score;
    }

    return degree;
  }
};