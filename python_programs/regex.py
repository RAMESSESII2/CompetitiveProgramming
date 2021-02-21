import regex as re

text="My email is _stmbhardwaj@gmail.com_ and the recovery email is bs-atyam012@gmail.com"

pattern=re.compile("[a-zA-Z0-9._\-]+@[a-zA-Z0-9]+\.[a-zA-Z]+")

# result=pattern.search(text)
result=pattern.findall(text)

print(result)
