# TODO
while True:
    h = input("Height: ")
    if (!isinstance(h, int)):
        print("foo")
    if (h in range(0, 9)):
        break
    print("h should in (1, 8)")

for i in range(h):
    print(" " * (h - i - 1), end="")
    print("#" * (i + 1), end="")
    print("  ", end="")
    print("#" * (i + 1))