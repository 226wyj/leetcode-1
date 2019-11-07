#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 advpetc <chenhaoy@usc.edu>
#
# Distributed under terms of the MIT license.

"""

"""
def prime(orders):
    """TODO: Docstring for prime.
    :returns: TODO

    """
    def comparator(order):
        id_, rest = order.split(" ", 1)
        return (0, rest, id_) if rest[0].isalpha() else (1, )
    return sorted(orders, key=comparator)
