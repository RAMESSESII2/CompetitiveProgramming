from memo import memo

@memo
def F(m, n):
    if 0 <= n <= m - 1:
        return 1
    else:
        return 1 + F(m, n - 1) + sum(F(m, n - r - 1) for r in range(m, n))


def threshold(m):
    for i in range(m, 1000):
        if F(m, i) >= 1000000:
            break
    return i


print(threshold(50))