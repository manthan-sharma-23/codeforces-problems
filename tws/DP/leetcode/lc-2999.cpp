#include <bits/stdc++.h>
#include <cstring>
#include <string>
using namespace std;

#define pii pair<int, int>
#define F first
#define S second
#define each(x, v) for (auto &x : v)
#define min_heap(T) priority_queue<T, vector<T>, greater<T>>
#define max_heap(T) priority_queue<T>
#define hash_map(T1, T2) unordered_map<T1, T2>
#define hash_set(T) unordered_set<T>
#define loop(i, a, b, step) for (int i = (a); i < (b); i += step)
#define asc(v) sort((v).begin(), (v).end())
#define dsc(v) sort((v).rbegin(), (v).rend())
#define ll long long
#define vi vector<int>
#define vll vector<ll>

class Solution {
public:
  long long pow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
      if (exp % 2 == 1) {
        result *= base;
      }
      base *= base;
      exp /= 2;
    }
    return result;
  }

  int numbers[10], limits[10];

  ll solve(int n, const string &s) {
    string g = to_string(n);

    if (s.length() > g.length())
      return 0;

    if (s.length() == g.length()) {
      if (stoi(s) <= n)
        return 1LL;
      else
        return 0LL;
    }

    ll count = 1LL, f = 1LL;
    for (int i = 1; i < g.length() - s.length(); i++) {
      count += (9 * f);
      f *= 10;
    }

    int finalLenght = g.length() - s.length();

    for (int i = 0; i < finalLenght; i++) {
      int h = g[i] - '0';
    }

    return count;
  }

  ll numberOfPowerfulInt(ll start, ll finish, int limit, string s) {
    for (int i = 0; i < 10; i++)
      numbers[i] = 0, limits[i] = 0;

    for (auto ch : s) {
      numbers[ch - '0']++;
    }

    for (int i = 0; i < 10; i++) {
      if (numbers[i] > limit) {
        return 0LL;
      }

      limits[i] = limit - numbers[i];
    }

    return 0LL;
  }
};

int main() {
  Solution s;

  s.numberOfPowerfulInt(15, 215, 6, "10");
}