class Solution {
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<vector<int>> paths;
            vector<int> path;
            dfs(graph, paths, path, 0);
            return paths;
        }

        void dfs(vector<vector<int>>& graph,
                 vector<vector<int>>& result,
                 vector<int> path, int cur) {
            path.push_back(cur);
            if (cur == graph.size() - 1) result.push_back(path);
            else {
                for (auto child : graph[cur]) dfs(graph, result, path, child);
            }
            path.pop_back();
        }
};
