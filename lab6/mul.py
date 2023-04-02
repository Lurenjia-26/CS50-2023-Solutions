import random
LENGTH = 10


def main():
    randLicense()
    estimate()


def randLicense():
    license = set()
    while True:
        license.add(random.randint(0, 9000))
        if (len(license) == LENGTH):
            break
    return


def estimate():
    


main()