import random
LENGTH = 10

def randLicense():
    license = set()
    for i in range(LENGTH):
        license.add(random.randint(0, 9000))