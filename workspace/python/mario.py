h = int(input("Height: "))

for i in range(h):
    print(" " * (h - i - 1), end="")
    print("#" * (i + 1), end="")
    print(" ", end="")
    print("#" * (i + 1))