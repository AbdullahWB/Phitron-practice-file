number=[4,10,15,20,25]
sum=0
for num in number:
    print(num)
    sum=sum+num
    print("sum num", sum)
    if sum<=num:
        print("sum is less than num")


text= "I love you sauda"
for index ,char in enumerate(text): # enumerate is used to print index and char
    print(index,char)
    if char=="a":
        print("I love you sauda")
    else:
        print("I hate you sauda")



for i in range(1,11,1):
    print("I love you sauda", i) 



items=['baseball','basketball','football']
for index, item in enumerate(items):
    print(index, item)



for i in range(5):
    print(i)