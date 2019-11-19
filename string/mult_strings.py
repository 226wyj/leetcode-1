#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 Haoyang <peter@peterchen.xyz>
#
# Distributed under terms of the MIT license.

"""
https://leetcode.com/problems/multiply-strings/

Input: num1 = "2", num2 = "3"
Output: "6"

Input: num1 = "123", num2 = "456"
Output: "56088"
"""


def multiply(num1, num2):
    """return the product in string

    :num1: TODO
    :num2: TODO
    :returns: TODO

    """
    digits = [0] * (len(num1) + len(num2))
    for i in reversed(range(len(num1))):
        for j in reversed(range(len(num2))):
            n1, n2 = int(num1[i]), int(num2[j])
            prod = n1 * n2
            p1, p2 = i + j, i + j + 1
            curr_sum = prod + digits[p2]
            digits[p1] += int(curr_sum / 10)
            digits[p2] = curr_sum % 10
    print(digits)

multiply("123", "456")
