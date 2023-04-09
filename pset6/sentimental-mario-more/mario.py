# TODO
while True:
    h = input("Height: ")
    if (isinstance(h, int)):
        h = int(h)
        if (h in range(0, 9)):
            print("h should in (1, 8)")
            break
    else:
        print("foo")


for i in range(h):
    print(" " * (h - i - 1), end="")
    print("#" * (i + 1), end="")
    print("  ", end="")
    print("#" * (i + 1))