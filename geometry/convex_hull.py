import sys


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def left_index(points):
    minm = 0
    for i in range(1, len(points)):
        if points[i].x < points[minm].x:
            minm = i
        elif points[i].x == points[minm].x:
            if points[i].y > points[minm].y:
                minm = i
    return minm


def orientation(p, q, r):
    # To find orientation of ordered triplet (p, q, r).
    #     The function returns following values
    #     0 --> p, q and r are colinear
    #     1 --> Clockwise
    #     2 --> Counterclockwise
    val = ((q.y - p.y) * (r.x - q.x)) - ((q.x - p.x) * (r.y - q.y))
    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return 2


def convex_hull(points, n):
    if n < 3:
        return
    left = left_index(points)
    hull = []
    p = left
    q = 0
    while True:
        hull.append(p)

        q = (p + 1) % n

        for i in range(n):
            if orientation(points[p], points[i], points[q]) == 2:
                q = i
        p = q

        if p == left:
            break
    for i in hull:
        print(f"{points[i].x}, {points[i].y}")


# points = []
# points.append(Point(0, 3))
# points.append(Point(2, 2))
# points.append(Point(1, 1))
# points.append(Point(2, 1))
# points.append(Point(3, 0))
# points.append(Point(0, 0))
# points.append(Point(3, 3))

# convex_hull(points, len(points))

if __name__ == "__main__":
    N = int(input())
    points = []
    for i in range(N):
        n, m = map(int, sys.stdin.readline().split())
        points.append(Point(n, m))
    convex_hull(points, N)
