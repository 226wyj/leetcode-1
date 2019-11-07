/*
 * draf.cpp
 * Copyright (C) 2019 advpetc <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int maxProduct(vector<int>& nums)
{
    int localMin = nums[0], localMax = nums[0];
    int ret = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        int currMax = max(
            nums[i], nums[i] > 0 ? nums[i] * localMax : nums[i] * localMin);
        int currMin = min(
            nums[i], nums[i] > 0 ? nums[i] * localMin : nums[i] * localMax);
        ret = max(ret, localMax);
        localMax = currMax;
        localMin = currMin;
    }
    return ret;
}
vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        int comple = 0 - nums[i];
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] == comple) {
                ret.push_back({ nums[i], nums[left], nums[right] });
                while (nums[left++] == nums[left]) {
                }
                while (nums[right++] == nums[right]) {
                }
            } else if (nums[left] + nums[right] < comple) {
                left++;
            } else {
                right--;
            }
        }
        return ret;
    }
}
