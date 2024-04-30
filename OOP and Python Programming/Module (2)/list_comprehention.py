number = [45, 67, 48, 65, 75, 78, 85, 95, 35, 55, 77]
odds=[]

for num in number:
    if num % 2 == 1 and num % 5 ==0:
        odds.append(num)

print(odds)

odd_nums = [num for num in number if num % 2 == 1 and num % 5 == 0]
print(odd_nums)


family=['abdullah', 'sauda', 'child']
relation= ['love', 'happy', 'understanding']

sub_num=[]
for name in family:
    print('name:', name)
    for rel in relation:
        print(name, rel)
        sub_num.append((name, rel))

print(sub_num)

age_comb2= [[name,rel] for name in family for rel in relation]
print(age_comb2)