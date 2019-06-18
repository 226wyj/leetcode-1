#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 Haoyang <peter@peterchen.xyz>
#
# Distributed under terms of the MIT license.

"""
response rate
"""


def test(bizOwnerId, allMessage):
    """sample function

    :bizOwnerId: TODO
    :allMessage: TODO
    :returns: TODO

    """
    def calc(wrote, total):
        from math import floor
        return floor(wrote / total * 100)

    

ret = test(42, [{"sender": 1, "recipient": 42, "conversationId": 1},
                {"sender": 42, "recipient": 1, "conversationId": 1),
                {"sender": 2, "recipient": 42, "conversationId": 2},
                {"sender": 2, "recipient": 42, "conversationId": 2},
                {"sender": 3, "recipient": 88, "conversationId": 3},
                {"sender": 3, "recipient": 42, "conversationId": 4}])
print(ret)
