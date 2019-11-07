/*
 * skiplist.cpp
 * Copyright (C) 2019 Haoyang <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

const int N = 1010;
int list[N][N];

int main(int argc, char *argv[]) 
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> list[1][i];
    }
    int j = 1;
    int _n = n;
    while (_n > 1) {
        int __n = _n;
        for (int i = 0; i < __n - 1; ++i) {
            auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
            if (i % 2 == 1 && gen()) {
                swap(list[j + 1][i], list[j][i]); 
            }
            else if (i % 2 == 0 && list[j][i - 1] != 0)
                swap(list[j + 1][i], list[j][i]);

        }
        j++;
    }
    return 0;
}

