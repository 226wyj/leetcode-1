#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

const int m = 6, n = 3;
unordered_map<string, unordered_map<string, string> > g; // src -> des : relationship
unordered_map<string, string> cache; // pre-record the calculated rel

void dfs(string src, string dst, string rel, unordered_set<string>& vis, vector<string>& path)
{
  vis.insert(src);

  if (rel != "")
    path.push_back(rel + " " + src);
  else
    path.push_back(src);
  if (src == dst)
    {
      for (int i = 0; i < (int) path.size(); ++i)
        cout << path[i] << " ";
      cout << endl;
    }
  else
    {
      unordered_map<string,string>::iterator i;
      for (i = g[src].begin(); i != g[src].end(); ++i) // iterate all the neighbours
        if (!vis.count(i -> first))
          dfs(i -> first, dst, g[src][i -> first], vis, path);
    }
  vis.erase(dst);
  if (rel != "")
    path.pop_back();
}

int main()
{
  string test[m][n] = {{"Bart", "brother", "Lisa"},
                       {"Bart", "son", "Homer"},
                       {"Marge", "wife", "Homer"},
                       {"Lisa", "daughter", "Homer"},
                       {"Lisa", "son", "Peter"},
                       {"Homer", "daughter", "Bart"}};
  string src = "Bart", dest = "Homer";

  for (int i = 0; i < m; ++i)
    g[test[i][0]][test[i][2]] = test[i][1];
  unordered_set<string> vis;
  vector<string> path;
  dfs(src, dest, "", vis, path);
  return 0;
}
