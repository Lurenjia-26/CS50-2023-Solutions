h = int(input("Height: "))

for i in range(h):
    for j in range(h):
        if j < h - i - 1:
            print(" ", end="")
        else:
            print("#", end="")