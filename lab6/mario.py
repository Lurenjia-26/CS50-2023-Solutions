def main():
    n = int(input("Height: "))
    mario(n)

def mario(n):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if i >= j:
                print(f"{j} * {i} = {i * j} ",end="")
        print("")

main()