/*
 * StringIterator.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;

class StringIterator {
public:
  deque<pair<char, int>> q;
  StringIterator(string compressedString) {
    char pre = compressedString[0];
    for (int i = 1, occ = 0; i < compressedString.size(); ++i) {
      if (compressedString[i] <= '9' && compressedString[i] >= '0') {
        occ *= 10;
        occ += compressedString[i] - '0';
      } else {
        q.push_back({pre, occ});
        pre = compressedString[i];
        occ = 0;
      }
    }
    cout << "brea";
  }

  char next() {
    if (!hasNext())
      return ' ';
    char res = q.front().first;
    if (--q.front().second <= 0) {
      q.pop_front();
    }
    return res;
  }

  bool hasNext() { return !q.empty(); }
};

int main() {
  StringIterator it("L1e2t1C1o1d1e1");
  cout << it.next();
  return 0;
}
/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
