def reverse(n):
    rev = 0

    while n > 0:
        r = n % 10
        rev = rev * 10 + r
        n = int(n / 10)

    return rev

x = int(input("Enter a number :"))

result = reverse(x)

print("\nReverse is :", result)
