import random
LENGTH = 10
MIN = 0
MAX = 1000


def main():
    li = randLicense()
    est(li)


def randLicense():
    li = set()
    while True:
        li.add(random.randint(MIN, MAX))
        if (len(li) == LENGTH):
            break
    return li


def est(li):
    print("Avg\t\tMedian\t\tGap\t\tAvg Gap")
    for i in range(5):
        li = list(li)
        li.sort()

        max0 = 2 * sum(li) / len(li)
        max1 = li[int(LENGTH / 2)] + li[int(LENGTH / 2 - 1)]
        max2 = li[LENGTH - 1] + li[0] - MIN
        max3 = int((1 + 1 / (LENGTH)) * li[LENGTH - 1])

        # print(li)
        print(f"{max0}\t\t{max1}\t\t{max2}\t\t{max3}")

    print(f"Answer: {MAX}")


main()
