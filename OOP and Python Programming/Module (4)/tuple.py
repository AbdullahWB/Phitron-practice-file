def make_tuple():
    return 3,4

print(make_tuple())


thing='pen', 'khata', 'notebook', 'mouse', 'keyboard', 'fan', 'mouse pad', 'multi usb', 'tripod', 'phone', 'jan', 'poran', 'sauda'
print(thing)


print(thing[0])
print(thing[-2])
print(thing[3:6])

if 'jan' in thing:
    print("sauda is my heart")
    
for item in thing:
    print(item)
    
numbers=([1,2,3],[10,20,30,40])
print(numbers[0])
numbers[0][1]=555
print(numbers)