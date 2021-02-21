import sys

sys.stdout = open("CP/output.txt", "w")
sys.stdin = open("CP/input.txt", "r")

from collections import deque

dr = [-1, 1, 0, 0]
dc = [0, 0, 1, -1]


if __name__ == "__main__":
    H, W = map(int, input().split())
    ch, cw = map(int, input().split())
    sx = ch - 1
    sy = cw - 1
    hh, hw = map(int, input().split())
    ex = hh - 1
    ey = hw - 1
    arr = []
    for i in range(H):
        arr.append(list(input()))
    arr[ex][ey] = "E"
    reached_end = False
    move_count = 0
    nodes_left_in_layer = 1
    nodes_in_next_layer = 0
    visited = [[False for i in range(W)] for j in range(H)]
    visited[sx][sy] = True

    print(visited)
    # directions vectors
    print(arr, dr, dc)
    def explore_neighbours(r,c,qx,qy,):
        nodes_in_next_layer = 0
        print(qx, qy)
        for i in range(4):
            rr = r + dr[i]
            cc = c + dc[i]
            if not legal(rr, cc):
                continue
            qx.appendleft(rr)
            qy.appendleft(cc)
            visited[rr][cc] = True
            nodes_in_next_layer += 1
        print(nodes_in_next_layer)
        return nodes_in_next_layer
    def legal(rr, cc):
        global arr, visited, H, W
        print(arr, visited)
        if rr < 0 or cc < 0 or rr >= H or cc >= W:
            return False
        if visited[rr][cc] or arr[rr][cc] == "#":
            return False
        return True

    def solve():
        global nodes_in_next_layer, nodes_left_in_layer, move_count, reached_end
        qx = deque()
        qy = deque()
        qx.append(sx)
        qy.append(sy)
        while len(qx) > 0:
            r = qx.popleft()
            c = qy.popleft()
            if arr[r][c] == "E":
                reached_end = True
                break
            nodes_in_next_layer = explore_neighbours(r, c, qx, qy)
            print(nodes_left_in_layer, nodes_in_next_layer, qx, qy)
            nodes_left_in_layer -= 1
            if nodes_left_in_layer == 0:
                nodes_left_in_layer = nodes_in_next_layer
                nodes_in_next_layer = 0
                move_count += 1
        if reached_end:
            return move_count, qx, qy
        return -1, qx, qy, visited
    

    print(solve())

"input looks like this "
4 4
1 1
4 3
..#.
..#.
.#..
.#..

OUTPUT
[['.', '.', '#', '.'], ['.', ' ', ' ', ' ', '.', '#', '.'], ['.', '#', '.', '.'], ['.', '#', 'E', '.']]
(-1, deque([]), deque([]), [[True, True, None, None], [True, True, None, None], [True, True, None, None], [True, True, None, None]])
