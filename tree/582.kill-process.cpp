class Solution {
    public:
        vector<int> ret;
        vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
                unordered_map<int, vector<int>> graph;
                if (pid.size() != ppid.size()) return {0};
                for (size_t i = 0; i < pid.size(); ++i)
                    graph[ppid[i]].push_back(pid[i]);
                dfs(graph, kill);
                return ret;
        }

        void dfs(unordered_map<int, vector<int>>& graph, int parent) {
            ret.push_back(parent);
            for(int child : graph[parent])
                dfs(graph, child);
        }
};
