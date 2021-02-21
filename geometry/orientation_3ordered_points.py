import sys


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def orientation(p1, p2, p3):
    val = (float(p2.y - p1.y) * (p3.x - p2.x)) - (float(p2.x - p1.x) * (p3.y - p2.y))
    if val > 0:
        # Clockwise
        return 6
    if val < 0:
        # Counter-Clockwise
        return 12
    else:
        # collinear
        return 0


if __name__ == "__main__":
    p = Point(0, 0)
    q = Point(4, 4)
    r = Point(1, 2)

    o = orientation(p, q, r)

    if o == 6:
        print("Clockwise")
    elif o == 12:
        print("Counter-Clockwise")
    else:
        print("Collinear")
