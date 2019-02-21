
class Solution {
	public:
		int findCircleNum(vector<vector<int>>& M) {
			vector<int> visited(M.size());
			unsigned count = 0;
			for (unsigned i = 0; i < M.size(); ++i) {
				if (visited[i] == 0) {
					dfs(M, visited, i);
					count++;
				}
			}
			return count;
		}

		void dfs(vector<vector<int>>& M, vector<int>& visited, unsigned i) {
			for (unsigned j = 0; j < M.size(); ++j) {
				if (M[i][j] == 1 && visited[j] == 0) {
					visited[j] = 1;
					dfs(M, visited, j);
				}
			}

		}
};
