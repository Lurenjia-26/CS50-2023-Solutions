def main():
    n = int(input)
    mario(n)


def mario(n):
    for i in range(n):
        for j in range(n):
            print("#")