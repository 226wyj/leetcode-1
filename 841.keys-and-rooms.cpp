class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            vector<bool> seen(rooms.size());
            seen[0] = true;
            stack<int> s;
            s.push(0);
            while (!s.empty()) {
                int node = s.top();
                s.pop();
                for (int n : rooms[node]) {
                    if (!seen[n]) {
                        seen[n] = true;
                        s.push(n);
                    }
                }

            }
            for (bool see : seen)
                if (!see) return false;
            return true;
        }
};
