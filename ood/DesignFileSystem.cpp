/*
 * DesignFileSystem.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;

class FileSystem {
public:
  struct Node {
    map<string, Node *> children;
    bool end = false;
    int val;
    Node(int value) : val(value) {}
  };
  Node *root;
  FileSystem() { root = new Node(-1); }
  bool insert(const vector<string> &path, int val) {
    Node *cur = root;
    int n = path.size();
    for (int i = 0; i < n - 1; i++) {
      if (!cur->children.count(path[i]))
        return false;
      cur = cur->children[path[i]];
    }
    if (cur->children.count(path[n - 1]))
      return false;
    cur->children[path[n - 1]] = new Node(val);
    return true;
  }
  int get(const vector<string> &path) {
    Node *cur = root;
    for (string p : path) {
      if (!cur->children.count(p))
        return -1;
      cur = cur->children[p];
    }
    return cur->val;
  }
  bool createPath(string path, int value) {
    auto raw = split(path);
    return insert(raw, value);
  }

  int get(string path) {
    auto raw = split(path);
    return get(raw);
  }

private:
  vector<string> inline split(string &path) {
    vector<string> res;
    for (int i = 1, j = 1; i < path.size(); ++i) {
      if (i == path.size() - 1) {
        res.push_back(path.substr(j, path.size()));
      } else if (path[i] == '/') {
        res.push_back(path.substr(j, i - j));
        j = i + 1;
      }
    }
    return res;
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
int main(int argc, char *argv[]) {
  FileSystem fs;
  cout << fs.createPath("/a", 1) << endl;
  cout << fs.get("/a") << endl;
  return 0;
}
