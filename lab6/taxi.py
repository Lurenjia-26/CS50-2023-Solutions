import random
LENGTH = 10


def main():
    li = randLicense()


def randLicense():
    li = set()
    while True:
        li.add(random.randint(0, 9000))
        if (len(li) == LENGTH):
            break
    return li


def est(li):
    max = sum(li) / len(li)


main()