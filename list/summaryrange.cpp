/*
 * summaryrange.cpp
 * Copyright (C) 2019 Haoyang <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) 
{
    vector<int> nums = { 0,2,3,4,6,8,9};
    const int n = nums.size(); 
    int i = 0;
    while (i < n) {
        int j = 1;
        while (i + j < n && (long) nums[i + j] - nums[i] == j) {
            ++j;
        }
        if (j <= 1) 
            cout << nums[i] << endl;
        else
            cout << nums[i] << "->" << nums[i + j - 1] << endl;
        i += j;
    }
    return 0;
}

