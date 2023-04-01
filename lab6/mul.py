def main():
    while True:
        try:
            n = input("Height: ")
            n = int(n)
            if n in range(1, 10):
                break
            elif n > 9:
                print("Too much!")
            elif n < 1:
                print("Are you kidding?")
        except ValueError:
            print(f"{n} is not an integer")
    mul(n)


def mul(n):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if i >= j:
                print(f"{j} * {i} = {i * j} ",end="")
        print("")


main()