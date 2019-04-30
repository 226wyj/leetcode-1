#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2019 advpetc <chenhaoy@usc.edu>
#
# Distributed under terms of the MIT license.

"""
Given a list(list()); 0: obs, 1: open, 9: target
find the shortest path from (0, 0) to target
"""
from collections import deque

def solver(grid):
    if len(grid) == 0: return 0
    width, height = len(grid), len(grid[0])
    q = deque([(0, 0, 0)]) # x, y, dist
    visited = set() 
    visited.add((0, 0))
    shortest_path = float("inf")
    
    while len(q) != 0:
        curr = q.popleft()
        # four directions
        for dir in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            if curr[0] + dir[0] >= width or curr[0] + dir[0] < 0: continue
            if curr[1] + dir[1] >= height or curr[0] + dir[0] < 0: continue
            curr_loc = (curr[0] + dir[0], curr[1] + dir[1])
            if grid[curr_loc[0]][curr_loc[1]] == 0: continue
            if grid[curr_loc[0]][curr_loc[1]] == 1 and curr_loc not in visited:
                visited.add(curr_loc)
                new_node = (curr_loc[0], curr_loc[1], curr[2] + 1)
                q.append(new_node)
            if grid[curr_loc[0]][curr_loc[1]] == 9:
                shortest_path = min(shortest_path, curr[2] + 1)
    print(shortest_path)

solver([[1, 1, 1, 0],
        [0, 1, 0, 0],
        [0, 1, 1, 9],
        [0, 1, 1, 1]])
