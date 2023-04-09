# TODO
while True:
    try:
        h = int(input("Height: "))
        if 1 <= h <= 8:
            break
    except ValueError:
        print("foo")

for i in range(h):
    print(" " * (h - i - 1), end="")
    print("#" * (i + 1), end="")
    print("  ", end="")
    print("#" * (i + 1))