class InvalidPrice(Exception):
    pass
class WrongCard(Exception):
    pass
try:
    raise InvalidPrice()
except InvalidPrice:
    print("InvalidPrice")
except WrongCard:
    print("WrongCard")
except Exception as e:
    print("Exception")

# try:
#     1/0
# except Exception:
#     print("Exception")
# except ZeroDivisionError:
#     print("Zero division")
