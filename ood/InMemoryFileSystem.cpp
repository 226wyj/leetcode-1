/*
 * InMemoryFileSystem.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;
class FileSystem {
public:
  struct Node {
    map<string, Node *> dirs; // dirname -> children
    map<string, string> files;
    vector<string> getNames() {
      vector<string> res;
      for (auto p : dirs)
        res.push_back(p.first);
      for (auto p : files)
        res.push_back(p.first);
      sort(res.begin(), res.end());
      return res;
    }
  };
  Node *root;
  FileSystem() { root = new Node(); }

  vector<string> ls(string path) {
    Node *curr = root;
    auto raw = split(path);
    if (raw.empty())
      return curr->getNames();
    for (int i = 0; i < raw.size() - 1; ++i) {
      curr = curr->dirs[raw[i]];
    }
    // last is file
    if (curr->files.count(raw.back())) {
      return {raw.back()};
    } else { // is directory
      curr = curr->dirs[raw.back()];
    }
    return curr->getNames();
  }

  void mkdir(string path) {
    Node *curr = root;
    auto raw = split(path);
    for (string d : raw) {
      if (!curr->dirs.count(d))
        curr->dirs[d] = new Node();
      curr = curr->dirs[d];
    }
  }

  void addContentToFile(string filePath, string content) {
    Node *curr = root;
    auto raw = split(filePath);
    for (int i = 0; i < raw.size() - 1; ++i) {
      curr = curr->dirs[raw[i]];
    }
    curr->files[raw.back()] += content;
  }

  string readContentFromFile(string filePath) {
    Node *curr = root;
    auto raw = split(filePath);
    for (int i = 0; i < raw.size() - 1; ++i) {
      curr = curr->dirs[raw[i]];
    }
    return curr->files[raw.back()];
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

void print(vector<string> str) {
  for (string s : str)
    cout << s << endl;
}
int main(int argc, char *argv[]) {
  FileSystem fs;
  print(fs.ls("/"));
  fs.mkdir("/a/b/c");
  fs.addContentToFile("/a/b/c/d", "hello");
  print(fs.ls("/"));
  cout << fs.readContentFromFile("/a/b/c/d");
  return 0;
}
