/*
 * juicer.cpp
 * Copyright (C) 2019 Haoyang <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    vector<int> input = {2,5,5,2};
    int n = (int)input.size();
    int res = 0;
    int i = 0;
    int prev_len = 0;
    while (i < n) {
        cout << res << endl;
        if (i + 1 < n && input[i + 1] > input[i]) {
            int increase = 1;
            while (i + 1 < n && input[i + 1] > input[i]) {
                i++;
                increase++;
            }
            res += (increase + 1) * increase >> 1;
            printf("increase: %d, add: %d\n", increase,
                (increase + 1) * increase >> 1);
            if (increase == prev_len)
                res++;
            prev_len = increase;
        } else {
            int decrease = 1;
            while (i + 1 < n && input[i + 1] < input[i]) {
                i++;
                decrease++;
            }
            res += (decrease + 1) * decrease >> 1;
            printf("decrease: %d, add: %d\n", decrease,
                (decrease + 1) * decrease >> 1);
            if (decrease == prev_len)
                res++;
            prev_len = decrease;
        }
        i++;
        cout << " i is: " << i << endl;
    }
    printf("res is: %d", res);
    return 0;
}
