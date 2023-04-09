# TODO
def get_number():
    while True:
        try:
            h = int(input("Height: "))
            if 1 <= h <= 8:
                break
        except ValueError:
