import random
LENGTH = 10


def main():
    randLicense()
    for i in license:
        print(i)


def randLicense():
    license = set()
    while True:
        license.add(random.randint(0, 9000))
        if (len(license) == LENGTH):
            break
    return


main()