import csv

with open("phonebook.csv", "a") as file:
    while True:
        name = input("Name: ")
        number = input("Number: ")

        if number == "-1":
            break

        writer = csv.writer(file)
        writer.writerow([name, f" {number}"])