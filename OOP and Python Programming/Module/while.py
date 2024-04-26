num=10
while num != 0:
    print(num)
    num -= 1


numB=0
while numB <= 10:
    numB += 1
    if numB % 2 == 0:
        print("even", numB)
    if numB % 2 == 1:
        print("odd", numB)
    if numB == 9:
        print("numB is 9")
        break
    if numB == 5:
        print("numB is 5")
        continue
    