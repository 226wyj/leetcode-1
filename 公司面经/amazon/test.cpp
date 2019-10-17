/*
 * test.cpp
 * Copyright (C) 2019 advpetc <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    string J = "aA";
    string S = "aAAbbbb";
    vector<bool> d(128, false);
    for (char j : J)
        d[j - 'A'] = true;
    int count = 0;
    for (char s : S) {
        if (d[s - 'A'])
            count++;
    }
    return 0;
}
