/*
 * nextPerm.cpp
 * Copyright (C) 2019 Haoyang <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void prt(vector<int>& arr)
{
    for (int i : arr) {
        std::cout << i << std::endl;
    }
}
int main(int argc, char* argv[])
{
    int sz;
    std::cin >> sz;
    vector<int> nums;
    for (int i = 0; i < sz; ++i) {
        int val;
        std::cin >> val;
        nums.push_back(val);
    }
    int k = sz - 1;
    while (k - 1 >= 0 && nums[k] <= nums[k - 1]) {
        k--;
    }
    printf("k is %d\n", k);
    if (k == 0) {
        reverse(nums.begin(), nums.end());
    } else {
        int l = sz - 1;
        while (l >= 0 && nums[l] <= nums[k - 1]) {
            l--;
        }
        swap(nums[l], nums[k - 1]);
        reverse(nums.begin() + k, nums.end());
    }
    prt(nums);
    return 0;
}
