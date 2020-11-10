/*
 * FirstUnique.cpp
 * Copyright (C) 2020 Haoyang <me@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <bits/stdc++.h>

using namespace std;
class FirstUnique {
public:
    queue<int> q;
    unordered_map<int, int> freq;
    FirstUnique(vector<int>& nums) {
        for (int v : nums) {
            add(v);
        }
    }
    
    int showFirstUnique() {
        while (!q.empty() && freq[q.front()] > 1) q.pop();
        return q.empty() ? -1 : q.front();
    }
    
    void add(int value) {
        freq[value]++;
        q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
int main(int argc, char *argv[])
{
    vector<int> nums = {2,3,5};
    FirstUnique f(nums);
    cout << f.showFirstUnique() << endl;
    f.add(2); // now 3 is first unique
    cout << f.showFirstUnique() << endl;
    return 0;
}

