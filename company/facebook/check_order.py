#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 Haoyang <peter@peterchen.xyz>
#
# Distributed under terms of the MIT license.

"""
check if the order of str is in given dict order
"""


def check(str, order):
    """

    :str: TODO
    :order: TODO
    :returns: bool

    """
    for i in range(1, len(str) - 1):
        if order.index(str[i]) < order.index(str[i - 1]):
            return False
    return True


print(check("abc", "cba"))
