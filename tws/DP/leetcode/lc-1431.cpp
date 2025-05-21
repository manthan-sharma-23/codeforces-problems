// codechef -> https://www.codechef.com/AUG14/problems/TSHIRTS

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int T, N;
vector<int> shirtOwners[101];
int dp[101][1 << 10];

int solve(int shirt, int mask, int allMask) {
  if (mask == allMask)
    return 1; // all people are assigned
  if (shirt > 100)
    return 0;

  if (dp[shirt][mask] != -1)
    return dp[shirt][mask];

  int res = solve(shirt + 1, mask, allMask) % MOD;

  for (int person : shirtOwners[shirt]) {
    if (!(mask & (1 << person))) {
      res += solve(shirt + 1, mask | (1 << person), allMask);
      if (res >= MOD)
        res -= MOD;
    }
  }

  return dp[shirt][mask] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;
  while (T--) {
    cin >> N;
    cin.ignore();

    for (int i = 1; i <= 100; ++i)
      shirtOwners[i].clear();

    for (int person = 0; person < N; ++person) {
      string line;
      getline(cin, line);
      stringstream ss(line);
      int shirtID;
      while (ss >> shirtID) {
        shirtOwners[shirtID].push_back(person);
      }
    }

    memset(dp, -1, sizeof(dp));
    int allMask = (1 << N) - 1;

    cout << solve(1, 0, allMask) << "\n";
  }

  return 0;
}
