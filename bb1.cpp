#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
struct Node {
    Node* next;
    int value;
    Node(int v) : value(v) {}
};
class Solution {
    public:
        // p1
        string candy(string s) {
            for (size_t i = 0, j = 0; i <= s.size(); ++i) {
                if (i < s.size() && s[i] == s[j]) continue;
                if (i - j >= 3)
                    return candy(s.substr(0, j) + s.substr(i));
                else j = i;
            }
            return s;
        }
        // p2
        unordered_set<int> m;
        vector<int> people(vector<int>& input, int k) {
            if (input.size() < k) return input;
            vector<int> ret;
            for (unsigned i = 0; i < input.size(); ++i) {
                if ((i + 1) % k == 0 && m.find(i) == m.end()) continue;
                else {
                    ret.push_back(input[i]);
                    m.insert(i);
                }
            }
            return people(ret, k);
        }
};

int main() {
    Solution s;
    // Candy: aabbbc -> aac
    //        aabbbac -> aaac -> c
    cout << "Start P1" << endl;
    string p1_1 = "aabbbc";
    string p1_2 = "aabbbac";
    cout << "p1 1: " << s.candy(p1_1) << endl;
    cout << "p1 2: " << s.candy(p1_2) << endl;

    // People sitting in a row:
    // input:   1 -> 2 - > 3 -> 4, k = 2
    // output:  1 -> 3 => 1
    cout << "Start P2" << endl;
    vector<int> input;
    for (int i = 1; i < 100; ++i)
        input.push_back(i);
    vector<int> output = s.people(input, 5);
    for (int o : output)
        cout << o;
    return 0;
}
