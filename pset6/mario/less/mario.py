from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height <= 8 and height >= 1:
        break

for i in range(height):
    for k in range(height-i-1):
        print(" ", end="")
    for j in range(i+1):
        print("#", end="")
    print()
        
