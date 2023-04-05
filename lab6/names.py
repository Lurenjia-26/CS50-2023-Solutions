import sys

# A list of names
names = ["Bill", "Bob", "Charlie", "Frank", "Jimmy", "Lena", "Tom", "Veronica"]

# Ask for name
name = input("Name: ")

# Seaerch for name
if name in names:
    print(f"Found! {name}")
    sys.exit(0)

print(f"Not Found {name}")
sys.exit(1)
