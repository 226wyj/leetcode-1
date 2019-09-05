import string


def solution(artifacts, N, searched):
    """return the [number of completed blocks, number of incomplete blocks]

    :artifacts: TODO
    :N: TODO
    :searched: TODO
    :returns: TODO

    """
    grid = [[""] * (N + 1) for _ in range(N + 1)]
    coordinates = artifacts.split(",")

    id_count = {}
    for coords in coordinates:
        ab = coords.strip().split(" ")
        # width, height = abs(int(ab[0][0] - ab[1][0])), abs(ord(ab[0][1] -
        # ord(ab[1][1])))
        id_count[coords] = {}
        id_count[coords][0] = 1  # not being touched yet
        id_count[coords][1] = 0
        # print("ab is: ", ab)
        for _x in range(int(ab[0][0]), int(ab[1][0]) + 1):
            for _y in range(ord(ab[0][1]) - 64, ord(ab[1][1]) - 64 + 1):
                print(ab[0][1], ab[1][1])
                print("x: ", _x, ", y: ", _y)
                grid[_x][_y] = coords
                id_count[coords][1] += 1

    for s in searched.strip().split():
        x, y = int(s[0]), ord(s[1]) - 65
        # print("x is ", x, "y is ", y)
        if grid[x][y] != "":
            id_count[grid[x][y]][0] = 0  # being touched
            id_count[grid[x][y]][1] -= 1
            grid[x][y] = ""

    completed, incomplete = 0, 0
    for id in id_count.keys():
        if id_count[id][1] == 0:
            completed += 1
        elif id_count[id][0] == 0:
            incomplete += 1

    return completed, incomplete


_complete, _incomplete = solution("1A 2A,12A 12A", 12, "12A")
print("complete: ", _complete, ", incomplete: ", _incomplete)
