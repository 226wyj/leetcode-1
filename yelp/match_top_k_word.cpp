/*
 * match_top_k_word.cpp
 * Copyright (C) 2019 Haoyang <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    int k = 3;
    vector<string> business_name_list
        = { "Super Burgers", "Super Duper Burgers", "Burgers" };
    string search_term = "Duper";
    auto cmp = [=](const string& left, const string& right) {
        bool l_exist = left.find(search_term) != string::npos;
        bool r_exist = right.find(search_term) != string::npos;
        if (!l_exist && !r_exist) {
            return left < right;
        } else if (l_exist && r_exist) {
            return left.find(search_term) < right.find(search_term);
        } else {
            return l_exist;
        }
    };
    sort(business_name_list.begin(), business_name_list.end(), cmp);
    for (string s : business_name_list) {
        std::cout << s << std::endl;
    }
    return 0;
}
