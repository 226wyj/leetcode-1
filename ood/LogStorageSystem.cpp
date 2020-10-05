/*
 * LogStorageSystem.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;
class LogSystem {
private:
  multimap<string, int> log;
  string low = "2000:00:00:00:00:00";
  string high = "2017:12:31:23:59:59";
  unordered_map<string, int> map = {{"Year", 4},    {"Month", 7},
                                    {"Day", 10},    {"Hour", 13},
                                    {"Minute", 16}, {"Second", 19}};

public:
  LogSystem() {}

  void put(int id, string timestamp) { log.emplace(timestamp, id); }

  vector<int> retrieve(string s, string e, string gra) {
    int len = map[gra];
    s = s.substr(0, len) + low.substr(len);
    e = e.substr(0, len) + high.substr(len);
    auto first = log.lower_bound(s);
    auto last = log.upper_bound(e);
    vector<int> result;
    for (auto it = first; it != last; it++)
      result.push_back(it->second);
    return result;
  }
};

void print(vector<int> &ids) {
  for (int i : ids)
    cout << i << endl;
}
int main(int argc, char *argv[]) {
  LogSystem log;
  log.put(1, "2017:01:01:23:59:59");
  log.put(2, "2017:01:01:22:59:59");
  log.put(3, "2016:01:01:00:00:00");
  auto res = log.retrieve("2016:01:01:01:01:01", "2017:01:01:23:00:00", "Year");
  print(res);
  res = log.retrieve("2016:01:01:01:01:01", "2017:01:01:23:00:00", "Hour");
  print(res);
  return 0;
}
