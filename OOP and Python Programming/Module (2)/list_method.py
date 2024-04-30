numbers=[200,10,20,30,40,50,60,70,80,90,100]

numbers.insert(-1,120)
numbers.append(110)
print(numbers)

# print(numbers)

if 120 in numbers:
    numbers.remove(120)

if 110 in numbers:
    numbers.remove(110)

print(numbers)

last=numbers.pop()
print(last,numbers)

if 50 in numbers:
    index= numbers.index(50)
    print(index,numbers)

sorted=numbers.sort()
print(numbers)

numbers.reverse()
print(numbers)