/*
 * water-flower.cpp
 * Copyright (C) 2019 Haoyang <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;
int plants[N];
int a, b;
int main(int argc, char* argv[])
{
    int sz;
    cin >> sz >> a >> b;
    printf("sz is %d, a is %d, b is %d\n", sz, a, b);
    for (int i = 0; i < sz; ++i) {
        cin >> plants[i];
    }
    int left = 0, right = sz - 1;
    int _a = a, _b = b;
    int res = 0;
    while (left < right) {
        if (plants[left] > _a) {
            res++;
            _a = a;
        } else {
            _a -= plants[left];
            left++;
        }

        if (plants[right] > _b) {
            res++;
            _b = b;
        } else {
            _b -= plants[right];
            right--;
        }
    }

    printf("remain a is: %d, remain b is: %d\n", _a, _b);
    std::cout << res << std::endl;
    return 0;
}
