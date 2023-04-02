import random
LENGTH = 10


def main():
    li = randLicense()
    est(li)


def randLicense():
    li = set()
    while True:
        li.add(random.randint(0, 1000))
        if (len(li) == LENGTH):
            break
    return li


def est(li):
    li = list(li)
    li.sort()
    max0 = 2 * sum(li) / len(li)
    max1 = max0
    print(li)
    print("Mean\t")
    print(f"{max0}\n{max1}")


main()