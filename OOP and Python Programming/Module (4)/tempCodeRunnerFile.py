numbers = [10, 15, 20, 35, 40, 10, 14, 15, 20]
doubled = lambda num: num * 2
doubled_num = map(doubled, numbers)
squared = map(lambda x: x * x, numbers)
print(numbers)
print(list(doubled_num))
print(list(squared))
