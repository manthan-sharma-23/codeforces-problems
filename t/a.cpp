#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long

struct TrieNode {
  TrieNode *children[26];
  TrieNode() {
    for (int i = 0; i < 26; ++i)
      children[i] = nullptr;
  }
};

// insert string into trie
void insert(TrieNode *root, const string &s) {
  TrieNode *node = root;
  for (char c : s) {
    int idx = c - 'a';
    if (!node->children[idx])
      node->children[idx] = new TrieNode();
    node = node->children[idx];
  }
}

// find lcp between s and what's already in trie
int lcp_trie(TrieNode *root, const string &s) {
  TrieNode *node = root;
  int len = 0;
  for (char c : s) {
    int idx = c - 'a';
    if (!node->children[idx])
      break;
    node = node->children[idx];
    len++;
  }
  return len;
}

int lcp(const string &a, const string &b) {
  TrieNode *root = new TrieNode();
  insert(root, a);
  int len = lcp_trie(root, b);
  // Memory cleanup skipped for brevity
  return len;
}

class Solution {
public:
  vector<int> longestCommonPrefix(vector<string> &words) {
    int n = words.size();
    vi maxS(n, 0);

    for (int i = 0; i < n - 1; i++) {
      maxS[i] = lcp(words[i], words[i + 1]);
    }

    for (auto s : maxS)
      cout << s << " ";
    cout << endl;

    vi pref(n, 0), suff(n, 0);

    pref[0] = maxS[0];
    for (int i = 1; i < n; i++) {
      pref[i] = max(pref[i - 1], maxS[i]);
    }

    suff[n - 1] = maxS[n - 1];
    for (int i = n - 3; i >= 0; i--) {
      suff[i] = max(suff[i + 1], maxS[i]);
    }

    vi res(n, 0);

    for (int i = 0; i < n; i++) {
      int maxL = 0;
      if (i > 1)
        maxL = max(maxL, pref[i - 2]);
      if (i < n - 1)
        maxL = max(maxL, suff[i + 1]);
      if (i > 0 && i < n - 1)
        maxL = max(maxL, lcp(words[i - 1], words[i + 1]));
      res[i] = maxL;
    }

    return res;
  }
};