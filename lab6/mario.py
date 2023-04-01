def main():
    n = int(input("Height: "))
    mario(n)

def mario(n):
    for i in range(n):
        for j in range(n):
            if i <= j:
                print("#",end="")
        print("")

main()