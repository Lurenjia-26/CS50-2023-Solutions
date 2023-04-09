# TODO
while True:
    h = int(input("Height: "))
    if (h in range(0, 9)):
        break
    print("foo")

for i in range(h):
    print(" " * (h - i - 1), end="")
    print("#" * (i + 1), end="")
    print("  ", end="")
    print("#" * (i + 1))