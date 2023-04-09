# TODO
while True:
    h = int(input("Height: "))
    if (h in range(1, 8)):
        break
    print("h should in [1, 8]")

for i in range(h):
    print(" " * (h - i - 1), end="")
    print("#" * (i + 1), end="")
    print(" ", end="")
    print("#" * (i + 1))