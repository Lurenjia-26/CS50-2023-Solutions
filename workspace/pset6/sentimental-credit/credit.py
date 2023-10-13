# TODO
import sys


def main():
    number = input("Number: ")
    length = len(str(number))

    if length != 13 and length != 15 and length != 16:
        print("INVALID")
        sys.exit()

    i = length - 2
    sum = 0
    while (i >= 0):
        if int(number[i]) < 5:
            sum += int(number[i]) * 2
        else:
            sum += 1 + (int(number[i]) * 2) % 10
        i -= 2

    i = length - 1
    while (i >= 0):
        sum += int(number[i])
        i -= 2

    check = int(number[0]) * 10 + int(number[1])
    if sum % 10 != 0:
        print("INVALID")
    else:
        if int(number[0]) == 4:
            print("VISA")
        elif check in [34, 37]:
            print("AMEX")
        elif 51 <= check <= 55:
            print("MASTERCARD")
        else:
            print("INVALID")


if __name__ == "__main__":
    main()
