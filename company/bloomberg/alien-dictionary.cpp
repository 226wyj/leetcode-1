/*
 * alien-dictionary.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;
string alienOrder(vector<string> &words) {
  set<pair<char, char>> path;
  unordered_set<char> unique;
  vector<int> inOrder(256);
  queue<char> q;
  string res;
  for (auto a : words) {
    unique.insert(a.begin(), a.end());
  }
  for (int i = 0; i < (int)words.size(); ++i) {
    int mn = min(words[i].size(), words[i + 1].size());
    int j = 0;
    for (; j < mn; ++j) {
      if (words[i][j] != words[i + 1][j]) {
        path.insert({words[i][j], words[i + 1][j]});
        break;
      }
    }
    if (j == mn && words[i].size() > words[i + 1].size())
      return "";
  }
  for (auto a : path) {
    ++inOrder[a.second];
  }
  for (auto a : unique) {
    if (inOrder[a] == 0) {
      q.push(a);
      res += a;
    }
  }
  while (!q.empty()) {
    char c = q.front();
    q.pop();
    for (auto a : path) {
      if (a.first == c) {
        --inOrder[a.second];
        if (inOrder[a.second] == 0) {
          q.push(a.second);
          res += a.second;
        }
      }
    }
  }
  return res.size() == unique.size() ? res : "";
}
int main(int argc, char *argv[]) {
  vector<string> dict = {"wrt", "wrf", "er", "ett", "rftt"};
  cout << alienOrder(dict);
  return 0;
}
