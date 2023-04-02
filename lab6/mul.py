import random
LENGTH = 10


def randLicense():
    license = set()
    while True:
        license.add(random.randint(0, 9000))
        if (len(license) == LENGTH):
            break
    return


randLicense()
for i in iter(license):
    print(i)