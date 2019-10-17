/*
 * calcuator.cpp
 * Copyright (C) 2019 Haoyang <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    stack<char> ops;
    stack<int> nums;
    string s = "(2+2)*(3+2)"; // 20
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(')
            continue;
        else if (s[i] == '+' || s[i] == '*')
            ops.push(s[i]);
        else if (s[i] == ')') {
            char op = ops.top();
            ops.pop();
            int left = nums.top();
            nums.pop();
            int right = nums.top();
            nums.pop();
            if (op == '+')
                nums.push(left + right);
            else if (op == '*')
                nums.push(left * right);
        } else {
            nums.push(s[i] - '0');
        }
    }
    printf("result of %s is %d", s.c_str(), nums.top());
    return 0;
}
