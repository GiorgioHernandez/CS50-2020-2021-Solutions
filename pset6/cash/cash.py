from cs50 import get_float

while True:
    owed = get_float("Change owed: ")
    if owed > 0:
        break

cents = round(owed*100)
count = 0

while cents > 0:
    if cents >= 25:
        cents -= 25
        count += 1
    elif cents >= 10:
        cents -= 10
        count += 1
    elif cents >= 5:
        cents -= 5
        count += 1
    else:
        cents -= 1
        count += 1
    
    
print(count)