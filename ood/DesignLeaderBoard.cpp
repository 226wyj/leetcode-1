/*
 * DesignLeaderBoard.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;
class Leaderboard {
public:
    unordered_map<int, int> data; // id, score
    set<pair<int, int>> s;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        // O(log(n)) for erase and insertion
        if (data.count(playerId)) s.erase({data[playerId], playerId});
        data[playerId] += score;
        s.insert({data[playerId], playerId});
    }
    
    int top(int K) {
        // O(K)
        int c = 0, res = 0;
        for (auto it = s.rbegin(); it != s.rend() && c < K; ++it, ++c)
            res += it->first;
        return res;
    }
    
    void reset(int playerId) {
        // O(log(n))
        s.erase({data[playerId], playerId});
        data[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
int main(int argc, char *argv[])
{
    Leaderboard l;
    l.addScore(1,73);
    l.addScore(2,56);
    l.addScore(3,39);
    l.reset(1);
    l.addScore(4,51);
    l.addScore(5,4);
    cout << l.top(1) << endl; // should ouput 56
    
    return 0;
}

