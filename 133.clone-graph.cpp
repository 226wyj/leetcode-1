/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
	public:
		// bfs traversal
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copies;
		// UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		//         if (!node) return NULL;
		//         UndirectedGraphNode* copy = new UndirectedGraphNode(node -> label);
		//         copies[node] = copy;
		//         queue<UndirectedGraphNode*> todo;
		//         todo.push(node);
		//         while (!todo.empty()) {
		//     	    UndirectedGraphNode* curr = todo.front();
		//     	    todo.pop();
		//     	    for (auto& neighbor : curr -> neighbors) {
		//     		    if (copies.find(neighbor) == copies.end()) {
		//     			    copies[neighbor] = new UndirectedGraphNode(neighbor -> label);
		//     			    todo.push(neighbor);
		//     		    }
		//     		    copies[curr] -> neighbors.push_back(copies[neighbor]);
		//     	    }
		//         }
		//         return copy;
		// }

		// dfs traversal

		UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
			if (!node) return NULL;
			if (copies.find(node) == copies.end()) {
				copies[node] = new UndirectedGraphNode(node -> label);
				for (auto& neighbor : node -> neighbors) {
					copies[node] -> neighbors.push_back(cloneGraph(neighbor));
				}
			}
			return copies[node];
		}
};
