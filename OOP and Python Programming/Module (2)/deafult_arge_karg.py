def sum(num1,num2,num3,num4=0):
    result = num1 + num2 + num3 + num4
    return result

total = sum(40,11,20)
# print("total:- ", total)

#args

def all_sum(num1,num2,*args):
    print(args)
    sum = num1+num2
    for num in args:
        sum=sum+num
    return sum

total = all_sum(20,30,40,50)
print("total:- ", total)