class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class ConvexHull:
    def outerTrees(self, p):
        points = []
        for point in p:
            pc = Point(point[0], point[1])
            points.append(pc)
        # Computes the cross product of vectors p1p2 and p2p3
        # value of 0 means points are colinear; < 0, cw; > 0, ccw

        def cross(p1, p2, p3):
            return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x)

        # Computes slope of line between p1 and p2
        def slope(p1, p2):
            return 1.0 * (p1.y - p2.y) / (p1.x - p2.x) if p1.x != p2.x else float("inf")

        # Find the smallest left point and remove it from points
        start = min(points, key=lambda p: (p.x, p.y))
        points.pop(points.index(start))

        # Sort points so that traversal is from start in a ccw circle.
        points.sort(key=lambda p: (slope(p, start), -p.y, p.x))

        # Add each point to the convex hull.
        # If the last 3 points make a cw turn, the second to last point is wrong.
        ans = [start]
        for p in points:
            ans.append(p)
            while len(ans) > 2 and cross(ans[-3], ans[-2], ans[-1]) < 0:
                ans.pop(-2)
        # return ans
        for p in ans:
            print(p.x, p.y)


H = ConvexHull()
print(H.outerTrees([[0, 0], [1, 1], [2, 2], [3, 3], [1, 2]]))
print(H.outerTrees([[0, 3], [1, 1], [2, 2], [3, 3], [1, -2]]))
print(H.outerTrees([[0, 0], [1, 1], [2, 2], [3, 3], [1, 2]]))
