/*
 * common_words.cpp
 * Copyright (C) 2019 Haoyang <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
/* #include <algorithm> */
/* #include <iostream> */
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    vector<char> str1 = { 'a', 'b', 'c' };
    vector<char> str2 = { 'a', 'a', 'd' };
    vector<int> m(
        26, 0); // 2->only in one of the str, 1->common word, 0->doesn't exist
    int common = 0, unique = 0;
    for (const char& s : str1)
        m[s - 'a'] = 2;
    for (const char& s : str2) {
        if (m[s - 'a'] == 2) {
            m[s - 'a'] = 1;
            common++;
        } else if (m[s - 'a'] == 0) {
            m[s - 'a'] = 2;
        }
    }
    for (const int& s : m) {
        if (s > 0)
            unique++;
    }
    printf("common is %d, unique is %d, ratio is %f\n", common, unique,
        (common / (double)unique));
    return 0;
}
