class Solution {
    public:
        bool validTree(int n, vector<vector<int>>& edges) {
            return method4(n, edges);
        }

        /******************************************************************************
        * Function:         bool method1
        * Description:      
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        bool method1(int n, vector<vector<int>>& edges){
            vector<int> roots(n, -1);
            for (auto i : edges) {
                int x = find(roots, i[0]), y = find(roots, i[1]);
                if (x == y) {
                    return false;
                }
                roots[x] = y;
            }
            return edges.size() == n - 1;
        }
        /******************************************************************************
        * Function:         int find
        * Description:      read in a graph, where index is node and value is the
                            connected node
        * Where:
        * Return:           the top root node of i-node
        * Error:            
        *****************************************************************************/
        int find(vector<int>& roots, int i){
            while (roots[i] != -1) {
                i = roots[i];
            }
            return i;
        }

        /******************************************************************************
        * Function:         bool method2
        * Description:      
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        bool method2(int n, vector<vector<int>>& edges){
            vector<vector<int>> g(n);
            vector<bool> visited(n, false);
            for (auto a : edges) {
                g[a[0]].push_back(a[1]);
                g[a[1]].push_back(a[0]);
            }
            // check if has cycle
            if (!dfs(g, visited, 0, -1)) {
                return false; 
            }

            // check if is connected
            for (auto a : visited) {
                if (!a) {
                   return false; 
                }
            }
            return true;
        }

        /******************************************************************************
        * Function:         bool dfs
        * Description:      
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        bool dfs(vector<vector<int>>& g, vector<bool>& visited, int curr, int pre){
            if (visited[curr])
                return false;
            visited[curr] = true;
            for (auto a : g[curr]) {
                if (a != pre) {
                    if (!dfs(g, visited, a, curr)) {
                        return false; 
                    } 
                } 
            }
            return true;
        }
        // bfs method
        bool method3(int n, vector<vector<int>>& edges) {
            vector<unordered_set<int>> g(n);
            unordered_set<int> visited({0});
            queue<int> q({0});
            for (auto a : edges) {
                g[a[0]].insert(a[1]);
                g[a[1]].insert(a[0]);
            }

            while (!q.empty()) {
                int t = q.front();
                q.pop();
                for (auto a : g[t]) {
                    if (visited.count(a)) {
                        return false; 
                    }
                    visited.insert(a);
                    q.push(a);
                    g[a].erase(t);
                }
            }
            return visited.size() == n;
        }

        /*! \brief Union Find
         *
         *  Using union find to find cycle
         *
         * \param n Parameter description
         * \param  Parameter description
         * \return Return parameter description
         */
        bool method4(int n, vector<vector<int>>& edges) {
            vector<int> roots(n, -1);
            for (auto a : edges) {
                int x = union_find(roots, a[0]);
                int y = union_find(roots, a[1]);
                if (x == y) return false;;
                roots[x] = y;
            }
            return edges.size() == n - 1;
        }

        /*! \brief Find for union find
         *
         *  find top root of current node
         *
         * \param roots get current node's root
         * \param i curr node
         * \return root node
         */
        int union_find(vector<int>& roots, int i)
        {
            while (roots[i] != -1) {
               i = roots[i];
            }
            return i;
        }
};
