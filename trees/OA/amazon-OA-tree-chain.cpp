#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int n;

  vector<vector<int>> adj;

  long long globalScore = 0;
  const int MOD = 1e9 + 7;

  int dfs(int node) {
    int maxLen = 0;

    for (auto child : adj[node]) {
      int t = dfs(child);

      if (t > maxLen) {
        globalScore += (maxLen * maxLen);
        maxLen = t;
      } else {
        globalScore += (t * t);
      }
    }

    return maxLen + 1;
  }

public:
  int maximumScore(vector<int> arr, int N) {
    n = N;

    adj.resize(n + 1);

    if (n <= 2) {
      return n * n;
    }

    for (int i = 0; i < arr.size(); i++) {
      adj[arr[i]].push_back(i + 2);
    }

    int maxLenRoot = dfs(1);

    globalScore += (maxLenRoot * maxLenRoot);

    return globalScore;
  }
};

int main() {
  int N = 5;
  vector<int> a = {1, 2, 3, 3};

  Solution s;
  cout << s.maximumScore(a, N) << endl;
}
