/*
 * missingrange.cpp
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
    const int lower = 0, upper = 99;
    vector<int> t = { 0, 1, 3, 50, 75, 101 };
    const int n = t.size();
    int l = lower;
    for (int i = 0; i <= n; ++i) {
        int r;
        if (i < n && t[i] <= upper)
            r = t[i];
        else
            r = upper + 1; // plus one because later will minus one
        if (l == r)
            ++l;
        else if (r > l) {
            if (r - l == 1)
                cout << l << endl;
            else
                cout << l << "->" << r - 1 << endl;
            l = r + 1;
        }
    }
    return 0;
}
