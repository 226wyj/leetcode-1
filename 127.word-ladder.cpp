// Bidirectionaly BFS
class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            // convert to set
            unordered_set<string> wordDict(wordList.begin(), wordList.end());
            if (wordDict.find(endWord) == wordDict.end()) return 0;
            unordered_set<string> beginSet{beginWord}; unordered_set<string> endSet{endWord};
            int step = 1;
            while (!beginSet.empty()){
                unordered_set<string> tempSet;
                ++step;
                // erase all the visited nodes from beginSet
                for (auto& s : beginSet)
                    wordDict.erase(s);
                for (auto& s : beginSet)
                    // iterate through all the letter of the node
                    for (unsigned i = 0; i < s.size(); ++i) {
                        string str = s;
                        // try each charactor from a to z
                        for (char c = 'a'; c <= 'z'; ++c) {
                            str[i] = c;
                            if (wordDict.find(str) == wordDict.end())
                                continue;
                            if (endSet.find(str) != endSet.end())
                                return step;
                            tempSet.insert(str); // store current node
                        }
                    }
                // choose the least branch factor's set
                if (tempSet.size() < endSet.size())
                    beginSet = tempSet;
                else {
                    beginSet = endSet;
                    endSet = tempSet;
                }
            }
            return 0;
        }
};
