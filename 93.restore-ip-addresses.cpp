class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            vector<string> sol;
            dfs(s, sol, 0, "", 0);
            return sol;
        }
        // ip: input s; sol: current *total* valid solution
        // restored: current *part* of solution, count: # of *part* of solution
        void dfs(string ip, vector<string>& sol, unsigned idx, string restored, unsigned count) {
            if (count > 4) return;
            // if all the four parts are valid
            if (count == 4 && idx == ip.size()) sol.push_back(restored);
            // bc ip can only btw len 1 - 3
            for (unsigned i = 1; i < 4; ++i) {
                if (idx + i > ip.size()) break;
                string s = ip.substr(idx, i);
                if ((s[0] == '0' && s.size() > 1) ||
                        (i == 3 && stoi(s) >= 256))
                    continue;
                dfs(ip, sol, idx + i, restored + s + (count == 3 ? "" : "."), count + 1);
            }
        }
};
